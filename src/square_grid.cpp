#include "wfc_grid.h"
#include "vector_slot.h"

const int N = 5;
const int M = 5;

// template <int N, int M>
class SquareGrid : public WFCGrid {
    VectorSlot *grid[N * M];

    public:
        SquareGrid(std::vector<bool> **vectors) {
            for (size_t i = 0; i < N * M; i++) {
                for (size_t j = 0 ; j < M; j++) {
                    grid[N * i + j] = new VectorSlot(vectors[i][j]);
                }
            }
        }

        ~SquareGrid() {
            for (size_t i = 0; i < N * M; i++) 
                delete grid[i];
        }

        Slot *getValue(int key) {
            return grid[key];
        }

        int *getNeighbors(int key) {
            //front, right, back, left
            int *neighbor_keys = new int[4];
            
            // if (key-1 < 0)

            
            return neighbor_keys;
        }

        int *getKeys() {
            int *keys = new int[N * M];
            for (size_t i = 0; i < N * M; i++) 
                keys[i] = (int) i;
            return keys;
        }

        Slot **getValues();

};