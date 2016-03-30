//
//  AUTStrongifyOr.h
//  Automatic
//
//  Created by Eric Horacek on 3/29/16.
//  Copyright © 2016 Automatic Labs. All rights reserved.
//

#import "metamacros.h"

/// Same as @strongify, but with an escape hatch if strongification fails.
///
/// @code
///
/// @strongifyOr(self) return [RACSignal empty];
///
/// @endcode
#define strongifyOr(...) \
    rac_keywordify \
    _Pragma("clang diagnostic push") \
    _Pragma("clang diagnostic ignored \"-Wshadow\"") \
    metamacro_foreach(rac_strongify_,, __VA_ARGS__) \
    _Pragma("clang diagnostic pop") \
    if (metamacro_foreach(__AUTIsNil,, __VA_ARGS__) false) \

// IMPLEMENTATION DETAILS FOLLOW!
// Do not write code that depends on anything below this line.

#define __AUTIsNil(INDEX, EXPRESSION) \
    (EXPRESSION == nil) ||

#define aut_strongify_(INDEX, VAR) \
    __strong __typeof__(VAR) VAR = metamacro_concat(VAR, _weak_);
