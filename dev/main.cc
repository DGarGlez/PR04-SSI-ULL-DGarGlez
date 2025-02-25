#include <iostream>
#include <vector>
/** 
 * Función para generar la secuencia C/A de GPS para un satélite específico.
 * @param sat_id ID del satélite (1-32).
 * @param longitud Longitud de la secuencia de salida.
 * @return Secuencia C/A generada.
 */
std::vector<int> generar_CA(int sat_id, int longitud) {
    // Registros de desplazamiento
    std::vector<int> G1(10, 1);
    std::vector<int> G2(10, 1);
    std::vector<int> salida;
    
    // Tap positions para cada satélite (valores específicos para cada ID)
    int taps[32][2] = {
        {2, 6}, {3, 7}, {4, 8}, {5, 9}, {1, 9}, {2, 10}, {1, 8}, {2, 9}, {3, 10}, {2, 3},
        {3, 4}, {5, 6}, {6, 7}, {7, 8}, {8, 9}, {9, 10}, {1, 4}, {2, 5}, {3, 6}, {4, 7},
        {5, 8}, {6, 9}, {1, 3}, {4, 6}, {5, 7}, {6, 8}, {7, 9}, {8, 10}, {1, 6}, {2, 7}, 
        {3, 8}, {4, 9}
    };
    
    for (int i = 0; i < longitud; i++) {
        // Generar bits de salida
        int bit_G1 = G1[9];
        int bit_G2 = G2[taps[sat_id - 1][0] - 1] ^ G2[taps[sat_id - 1][1] - 1];
        
        salida.push_back(bit_G1 ^ bit_G2);
        
        // Desplazamiento y realimentación
        int nuevo_G1 = G1[2] ^ G1[9];
        int nuevo_G2 = G2[1] ^ G2[2] ^ G2[5] ^ G2[7] ^ G2[8] ^ G2[9];
        
        for (int j = 9; j > 0; j--) {
            G1[j] = G1[j - 1];
            G2[j] = G2[j - 1];
        }
        G1[0] = nuevo_G1;
        G2[0] = nuevo_G2;
    }
    
    return salida;
}

int main() {
    int sat_id, longitud;
    std::cout << "Ingrese el ID del satélite (1-32): ";
    std::cin >> sat_id;
    if (sat_id < 1 || sat_id > 32) {
        std::cerr << "ID de satélite inválido. Debe estar entre 1 y 32." << std::endl;
        return 1;
    }
    std::cout << "Ingrese la longitud de la secuencia de salida: ";
    std::cin >> longitud;
    if (longitud <= 0) {
        std::cerr << "Longitud de secuencia inválida. Debe ser mayor a 0." << std::endl;
        return 1;
    }
    
    std::vector<int> secuencia = generar_CA(sat_id, longitud);
    
    std::cout << "Secuencia C/A generada: ";
    for (int bit : secuencia) {
        std::cout << bit;
    }
    std::cout << std::endl;
    
    return 0;
}