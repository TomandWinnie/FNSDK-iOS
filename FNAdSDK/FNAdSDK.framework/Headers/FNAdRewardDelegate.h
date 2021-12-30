//
//  FNAdRewardDelegate.h
//  FNDrawAd
//
//  Created by ALAN on 2021/10/21.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol FNAdRewardDelegate <NSObject>

/// 请求开始回调
- (void)fnad_contentRequestStart;

/// 请求成功回调
- (void)fnad_contentRequestSuccess;

/// 请求失败回调
- (void)fnad_contentRequestFail;

///  视频开始播放
- (void)fnad_videoDidStartPlay;

/// 视频暂停播放
- (void)fnad_videoDidPause;

/// 视频恢复播放
- (void)fnad_videoDidResume;

/// 视频停止播放
- (void)fnad_videoDidEndPlay;

/// 视频播放失败
- (void)fnad_videoDidFailedToPlay;
@end

NS_ASSUME_NONNULL_END
