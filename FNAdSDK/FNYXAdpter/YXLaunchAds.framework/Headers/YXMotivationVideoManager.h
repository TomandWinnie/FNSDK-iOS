//
//  YXMotivationVideoManager.h
//  LunchAd
//
//  Created by shuai on 2018/11/29.
//  Copyright © 2018 YX. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@protocol YXMotivationDelegate;

@interface YXMotivationVideoManager : NSObject

@property(nonatomic,weak) id<YXMotivationDelegate> delegate;

/* 媒体位 */
@property (nonatomic, copy) NSString *mediaId;

/**
 开始请求视频
 */
- (void)loadVideoPlacement;

/**
 展示视频
 */
- (void)showVideoFromViewController:(UIViewController *)viewController;

//获取用户后台校验的UUID
- (NSString *)getVideoFlishUUID;

@end

@protocol YXMotivationDelegate <NSObject>

@optional

/**
 adValid 激励视频广告-视频-加载成功
 @param adValid 物料有效 数据不为空且没有展示过为 YES, 重复展示不计费.
 */
- (void)rewardedVideoDidLoad:(BOOL)adValid RewardAD:(YXMotivationVideoManager *)rewardedVideoAd;

/**
 adValid 激励视频广告点击下载
 
 @param adValid 物料有效 数据不为空且没有展示过为 YES, 重复展示不计费.
 */
- (void)rewardedVideoDidClick:(BOOL)adValid RewardAD:(YXMotivationVideoManager *)rewardedVideoAd;

/**
 adValid 激励视频广告素材加载失败
  @param error 错误对象
 */
- (void)rewardedVideoDidFailWithError:(NSError *)error RewardAD:(YXMotivationVideoManager *)rewardedVideoAd;

/**
 adValid 激励视频广告播放达到激励条件
 
 @param adValid 物料有效 数据不为空且没有展示过为 YES, 重复展示不计费.
 */
- (void)rewardedVideoAdDidRewardEffective:(BOOL)adValid RewardAD:(YXMotivationVideoManager *)rewardedVideoAd;

/**
 adValid 激励视频广告播放完成
 
 @param adValid 物料有效 数据不为空且没有展示过为 YES, 重复展示不计费.
 */
- (void)rewardedVideoDidPlayFinish:(BOOL)adValid RewardAD:(YXMotivationVideoManager *)rewardedVideoAd;

/**
 adValid 激励视频广告已经关闭
 */
- (void)rewardedVideoDidClose:(YXMotivationVideoManager *)rewardedVideoAd;

/**
adValid 激励视频播放页即将打开
*/
- (void)rewardVideoAdWillVisible:(YXMotivationVideoManager *)rewardedVideoAd;

/**
 adValid 激励视频广告点击了跳过按钮
 */
- (void)rewardedVideoSkipBtnClick:(YXMotivationVideoManager *)rewardedVideoAd;

@end

NS_ASSUME_NONNULL_END
