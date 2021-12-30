//
//  NSObject+FNProperty.h
//  FNAD
//
//  Created by ALAN on 2021/7/17.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSObject (FNProperty)

/**环境  YES生产环境  NO开发环境*/
@property(nonatomic,assign) BOOL isRelease;


@end

NS_ASSUME_NONNULL_END
