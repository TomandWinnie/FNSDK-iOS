//
//  FNInitalizeBanner.h
//  FNAD
//
//  Created by ALAN on 2021/5/11.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


@protocol FNLoadBannerAdDelegate <NSObject>


@optional

/**
 *  请求广告条数据失败后调用
 *  详解:当接收服务器返回的广告数据失败后调用该函数
 */
- (void)fnBannerError:(NSError *)error;


/**
 *  banner广告曝光
 */
- (void)fnBannerShow;


/**
 *  banner条被用户关闭时调用
 *  详解:用户有可能点击关闭按钮从而把广告条关闭
 */
- (void)fnBannerClosed;

/**
 * 点击回调
 */
- (void)fnBannerViewClicked;

@end

@interface FNInitalizeBanner : NSObject

/**委托对象*/
@property(nonatomic,weak) id<FNLoadBannerAdDelegate> delegate;


/**初始化当前类*/
+ (instancetype)shareFnBanner;


/**初始化SDK*/
/**params adsID 由平台分配初始化ID*/
/**params adsID 由平台分配广告位ID*/
/**params viewcontroller   当前self*/
- (void)loadFnBannerAd:(NSString *)appid ADS:(NSString *)adsID    initWithView:(UIView *)view;
@end

NS_ASSUME_NONNULL_END
