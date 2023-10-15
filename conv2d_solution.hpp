#ifndef conv2d_SOLUTION_INCLUDED
#define conv2d_SOLUTION_INCLUDED
#include <cstdlib>
#include "archlab.h"
#include <unistd.h>
#include<cstdint>
#include"function_map.hpp"


#define TILE_SIZE 64
//template<typename T>
void __attribute__((noinline)) conv2d_solution(int64_t **M, int64_t **K, uint32_t m_size, uint32_t k_size, int64_t **R) {
		      // parameters you can use for whatever purpose you want (e.g., tile sizes)
    int32_t border;
    border = m_size-k_size;

	for(int32_t i = 0; i < border; i+=TILE_SIZE) {
		for(int32_t j = 0; j < border; j+=TILE_SIZE) {
            for(int32_t ii = i; ii < i+TILE_SIZE && ii < border ; ii++) {
                for(int32_t jj = j; jj < j+TILE_SIZE && jj < border; jj++) {
                        int64_t sum=0;
                        for(int32_t x = 0; x < k_size && ii+x < m_size; x++) {
                        for(int32_t y = 0; y < k_size && jj+y < m_size; y++) {
                            sum += M[ii+x][jj+y] * K[x][y];
                            }
                        }
                    R[ii][jj] = sum;
                    }

                    
                }
            }
       }

    return;
}

#endif
