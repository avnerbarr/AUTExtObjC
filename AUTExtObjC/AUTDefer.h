//
//  Defer.h
//
//
//  Created by Avner Barr


// http://nshipster.com/new-years-2016/
#ifndef Defer_h
#define Defer_h
// some helper declarations
#define _nob_macro_concat(a, b) a##b
#define nob_macro_concat(a, b) _nob_macro_concat(a, b)
typedef void(^nob_defer_block_t)();
NS_INLINE void nob_deferFunc(__strong nob_defer_block_t *blockRef)
{
    nob_defer_block_t actualBlock = *blockRef;
    actualBlock();
}

// the core macro
#define nob_defer(deferBlock) \
__strong nob_defer_block_t nob_macro_concat(__nob_stack_defer_block_, __LINE__) __attribute__((cleanup(nob_deferFunc), unused)) = deferBlock

#endif /* Defer_h */
