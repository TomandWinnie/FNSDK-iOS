//
//  FNADManagers.h
//  FNAD
//
//  Created by ALAN on 2021/11/12.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface FNADManagers : NSObject

/// 单例
+ (instancetype)sharefnADManager;


/// 初始化数据
/// @param appid FNappid
- (void)initWithFNAppID:(NSString *)appid;
@end

NS_ASSUME_NONNULL_END
