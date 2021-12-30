//
//  FNOnlySDKDefines.h
//  FNAD
//
//  Created by ALAN on 2021/6/22.
//

#ifndef FNOnlySDKDefines_h
#define FNOnlySDKDefines_h
/**
 *  视频播放器状态
 *
 *  播放器只可能处于以下状态中的一种
 *
 */
typedef NS_ENUM(NSUInteger, FNMediaPlayerStatus) {
    FNMediaPlayerStatusInitial = 0,         // 初始状态
    FNMediaPlayerStatusLoading = 1,         // 加载中
    FNMediaPlayerStatusStarted = 2,         // 开始播放
    FNMediaPlayerStatusPaused = 3,          // 用户行为导致暂停
    FNMediaPlayerStatusError = 4,           // 播放出错
    FNMediaPlayerStatusStoped = 5,          // 播放停止
};


#endif /* FNOnlySDKDefines_h */
