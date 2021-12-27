//
//  FNInitalizeRardVideo.h
//  FNAD
//
//  Created by ALAN on 2021/5/11.
//

#import <Foundation/Foundation.h>
#import "FNLoadReardVideoAdDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@interface FNInitalizeRardVideo : NSObject

/**
 *  委托对象
 */
@property(nonatomic,weak) id<FNLoadReardVideoAdDelegate> delegate;

/**用户的userid*/
@property(nonatomic, copy) NSString *userIdentifier;

/**可扩展参数*/
@property(nonatomic, copy) NSString *extraInfo;


/// 构造方法
/// @param appId 联系商务分配appId
/// @param adsId 联系商务分配adsId
- (instancetype)initWithPlacementId:(NSString *)appId adsId:(NSString *)adsId;


/// 加载并显示
- (void)loadAndShowFnRardVidelAd:(UIViewController *)rootViewController;



/// 加载广告<load>
- (void)loadFnRardVidelAd;

/// 显示
/// @param rootViewController 用于显示激励视屏
- (void)showFNAdFromRootViewController:(UIViewController *)rootViewController;


@end

NS_ASSUME_NONNULL_END
