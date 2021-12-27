//
//  FNLoadInterstitialAdDelegate.h
//  FNAD
//
//  Created by ALAN on 2021/5/11.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol FNLoadInterstitialAdDelegate <NSObject>
@optional
/**
 *  广告预加载失败回调
 *  详解:当接收服务器返回的广告数据失败后调用该函数
 *   @param error 发生错误时会有相应的code和message
 */
- (void)fnInterstitialError:(NSError *)error;

/**
 *  插屏广告视图展示成功回调
 *  详解: 插屏广告展示成功回调该函数
 */
- (void)fnInterstitialShow;

/**
 *  插屏广告展示结束回调
 *  详解: 插屏广告展示结束回调该函数
 */
- (void)fnInterstitialClosed;


/**
 *  插屏广告点击回调
 *  详解: 插屏广告点击后回调该函数
 */
- (void)fnInterstitialClicked;

@end

NS_ASSUME_NONNULL_END
