//
//  types.h
//  AppleIntelWifiAdapter
//
//  Created by qcwap on 2020/1/5.
//  Copyright © 2020 钟先耀. All rights reserved.
//

#ifndef types_h
#define types_h

#include <IOKit/IOTypes.h>
#include <libkern/OSAtomic.h>
#include "bitfield.h"

#define __packed __attribute__((packed))
#define __aligned(x)        __attribute__((aligned(x)))
#define __must_check        __attribute__((warn_unused_result))

#define MODULE_FIRMWARE(fw)
#define MODULE_DESCRIPTION(x)
#define MODULE_AUTHOR(x)
#define MODULE_LICENSE(x)

#define __init
#define __exit

#define module_init(x)
#define module_exit(x)

#define pr_info(x)

#define __rcu

# define __acquires(x)
# define __releases(x)
# define __acquire(x) (void)0
# define __release(x) (void)0

#define might_sleep()

#define __bitwise
#define __force

#define WARN_ON(x) (x)
#define WARN_ON_ONCE(x) (x)

#define __stringify OS_STRINGIFY

#define BUILD_BUG_ON(condition) ((void)sizeof(char[1 - 2*!!(condition)]))


typedef UInt8  u8;
typedef UInt16 u16;
typedef UInt32 u32;
typedef UInt64 u64;

typedef u8 __u8;
typedef u16 __u16;
typedef u32 __u32;
typedef u64 __u64;

typedef __u16 __le16;
typedef __u16 __be16;
typedef __u32 __le32;
typedef __u64 __le64;

typedef SInt8  s8;
typedef SInt16 s16;
typedef SInt32 s32;
typedef SInt64 s64;

typedef s8  __s8;
typedef s16 __s16;
typedef s32 __s32;
typedef s64 __s64;

typedef UInt16 __sum16;

typedef u64 dma_addr_t;

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

#define upper_32_bits(n) ((u32)(((n) >> 16) >> 16))

#define lower_32_bits(n) ((u32)(n))

#define cpu_to_le64 __cpu_to_le64
#define le64_to_cpu __le64_to_cpu
#define cpu_to_le32 __cpu_to_le32
#define le32_to_cpu __le32_to_cpu
#define cpu_to_le16 __cpu_to_le16
#define le16_to_cpu __le16_to_cpu
#define cpu_to_be64 __cpu_to_be64
#define be64_to_cpu __be64_to_cpu
#define cpu_to_be32 __cpu_to_be32
#define be32_to_cpu __be32_to_cpu
#define cpu_to_be16 __cpu_to_be16
#define be16_to_cpu __be16_to_cpu

#define __cpu_to_le64(x) ((__force __le64)(__u64)(x))
#define __le64_to_cpu(x) ((__force __u64)(__le64)(x))
#define __cpu_to_le32(x) ((__force __le32)(__u32)(x))
#define __le32_to_cpu(x) ((__force __u32)(__le32)(x))
#define __cpu_to_le16(x) ((__force __le16)(__u16)(x))
#define __le16_to_cpu(x) ((__force __u16)(__le16)(x))
#define __cpu_to_be64(x) ((__force __be64)__swab64((x)))
#define __be64_to_cpu(x) __swab64((__force __u64)(__be64)(x))
#define __cpu_to_be32(x) ((__force __be32)__swab32((x)))
#define __be32_to_cpu(x) __swab32((__force __u32)(__be32)(x))
#define __cpu_to_be16(x) ((__force __be16)__swab16((x)))
#define __be16_to_cpu(x) __swab16((__force __u16)(__be16)(x))

#define le32_to_cpup __le32_to_cpup
#define le16_to_cpup __le16_to_cpup


static inline __u32 __le32_to_cpup(const __le32 *p)
{
    return (__force __u32)*p;
}

static inline __u16 __le16_to_cpup(const __le16 *p)
{
    return (__force __u16)*p;
}

#define ETHTOOL_FWVERS_LEN    32


#define RT_ALIGN_T(u, uAlignment, type) ( ((type)(u) + ((uAlignment) - 1)) & ~(type)((uAlignment) - 1) )
#define RT_ALIGN_Z(cb, uAlignment)              RT_ALIGN_T(cb, uAlignment, size_t)
#define LNX_ALIGN RT_ALIGN_Z

#define ALIGN_MASK(x, mask) (((x) + (mask)) & ~(mask))
#define ALIGN(x, a)         ALIGN_MASK(x, (typeof(x))(a) - 1)

#define usec_delay(x)           IODelay(x)
#define msec_delay(x)           IOSleep(x)
#define udelay(x)               IODelay(x)
#define mdelay(x)               IODelay(1000*(x))
#define msleep(x)               IOSleep(x)

#define DIV_ROUND_UP(n,d) (((n) + (d) - 1) / (d))
#define usleep_range(min, max)    msleep(DIV_ROUND_UP(min, 1000))

#endif /* types_h */
