/* f32v3_Reduce_AVX.h
 * 
 * Author           : Alexander J. Yee
 * Date Created     : 06/05/2017
 * Last Modified    : 06/05/2017
 * 
 */

#ifndef _flops_f32v3_Reduce_AVX_H
#define _flops_f32v3_Reduce_AVX_H
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  Dependencies
#include <immintrin.h>
namespace Flops{
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
inline float reduce(__m256 y){
    __m128 x = _mm_add_ps(_mm256_castps256_ps128(y), _mm256_extractf128_ps(y, 1));
    x = _mm_add_ps(x, _mm_unpackhi_ps(x, x));
    x = _mm_add_ps(x, _mm_shuffle_ps(x, x, 1));
    return _mm_cvtss_f32(x);
}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
}
#endif
