//
//  FNLoadReardVideoAdDelegate.h
//  FNAD
//
//  Created by ALAN on 2021/5/11.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol FNLoadReardVideoAdDelegate <NSObject>

/**
 视频广告加载成功回调
 */
- (void)fnRewardVideoAdDidLoad;


/**
 视频广告曝光回调
 */
- (void)fnRewardVideoShow;

/**
 视频播放页关闭回调
 */
- (void)fnRewardVideoClosed;


/**
 视频广告各种错误信息回调
 @param error 具体错误信息
 */
- (void)fnRewardVideoError:(NSError *)error;


/**
 视频广告播放达到激励条件回调
 */
- (void)fnRewardVideoReward;


/**
 视频广告点击回调
 */
- (void)fnRewardVideoClicked;


@end

NS_ASSUME_NONNULL_END
