#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Eslabon {
    int inicio, fin, peso;

    // Constructor
    Eslabon(int i, int f, int p) : inicio(i), fin(f), peso(p) {}
};

bool compararEslabones(const Eslabon &a, const Eslabon &b) {
    return a.peso < b.peso;
}

class UnionFind {
private:
    vector<int> padre, rango;

public:
    UnionFind(int n) {
        padre.resize(n);
        rango.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            padre[i] = i;
        }
    }

    int encontrar(int x) {
        if (padre[x] != x) {
            padre[x] = encontrar(padre[x]);
        }
        return padre[x];
    }

    void unir(int x, int y) {
        int raizX = encontrar(x);
        int raizY = encontrar(y);

        if (raizX != raizY) {
            if (rango[raizX] < rango[raizY]) {
                padre[raizX] = raizY;
            } else if (rango[raizX] > rango[raizY]) {
                padre[raizY] = raizX;
            } else {
                padre[raizX] = raizY;
                rango[raizY]++;
            }
        }
    }
};

vector<Eslabon> construirCadenaMinimaCosto(const vector<Eslabon> &eslabones) {
    int n = eslabones.size();
    vector<Eslabon> resultado;

    // Ordenar los eslabones por peso de manera ascendente
    vector<Eslabon> eslabonesOrdenados = eslabones;
    sort(eslabonesOrdenados.begin(), eslabonesOrdenados.end(), compararEslabones);

    // Inicializar estructura de conjuntos disjuntos
    UnionFind conjuntosDisjuntos(n);

    // Construir la cadena mínima
    for (const Eslabon &eslabon : eslabonesOrdenados) {
        int raizInicio = conjuntosDisjuntos.encontrar(eslabon.inicio);
        int raizFin = conjuntosDisjuntos.encontrar(eslabon.fin);

        // Verificar si la unión forma un ciclo
        if (raizInicio != raizFin) {
            resultado.push_back(eslabon);
            conjuntosDisjuntos.unir(raizInicio, raizFin);
        }
    }

    return resultado;
}

int main() {
    // Ejemplo de uso
    vector<Eslabon> eslabones = {
        {0, 1, 2},
        {1, 2, 5},
        {2, 3, 1},
        {3, 4, 3}
    };

    vector<Eslabon> resultado = construirCadenaMinimaCosto(eslabones);

    // Imprimir la cadena mínima
    cout << "Forma de construir la cadena con menor coste total:" << endl;
    for (const Eslabon &eslabon : resultado) {
        cout << "Unir eslabones " << eslabon.inicio << " y " << eslabon.fin << " con peso " << eslabon.peso << endl;
    }

    return 0;
}