//
//  FNDrawAdObject.h
//  FNDrawAd
//
//  Created by ALAN on 2021/10/22.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "FNAdRewardDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@interface FNDrawAdObject : NSObject

@property (nonatomic, strong) UIViewController *viewController;
@property (nonatomic,weak)id<FNAdRewardDelegate> delegate;


/// 单例
+ (instancetype)shareFnDrawAd;


/// 初始化广告
/// @param appid appid
/// @param adsid adsid
- (instancetype)initWithAdAppId:(NSString *)appid  ads:(NSString *)adsid;

/// 加载并显示
/// @param viewController 返回一个显示广告的UIViewController
- (void)loadAndShow:(void(^)(UIViewController *vc))viewController;

@end

NS_ASSUME_NONNULL_END
