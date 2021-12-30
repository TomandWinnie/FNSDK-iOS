//
//  FNLoadSplashAdDelegate.h
//  FNAD
//
//  Created by ALAN on 2021/5/11.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol FNLoadSplashAdDelegate <NSObject>


/**
 *  开屏广告成功展示
 */
- (void)fnSplashShow;


/**
 *  开屏广告失败（最终请求失败）
 */
- (void)fnSplashError:(NSError *)error;


/**
 *  开屏广告关闭回调
 */
- (void)fnSplashClosed;


/**
 *  开屏广告点击回调
 */
- (void)fnSplashClicked;

@end

NS_ASSUME_NONNULL_END
