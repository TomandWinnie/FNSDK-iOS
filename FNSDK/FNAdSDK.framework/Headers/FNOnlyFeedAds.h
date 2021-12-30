//
//  FNOnlyFeedAds.h
//  FNAD
//
//  Created by ALAN on 2021/6/18.
//

#import <Foundation/Foundation.h>
//#import "FNOnlyNativeAdDataObject.h"

NS_ASSUME_NONNULL_BEGIN

@protocol FNOnlyFeedAdsDelegate <NSObject>

/**
 广告数据回调
 @param onlyNativeAdDataObjects 广告数据数组
 @param error 错误信息
 */
- (void)fn_onlyNativeAdLoaded:(NSArray * _Nullable)onlyNativeAdDataObjects error:(NSError * _Nullable)error;


/**
 广告曝光回调
 */
- (void)fn_onlyNativeAdViewWillExpose;


/**
 广告点击回调
 */
- (void)fn_onlyNativeAdViewDidClick;


/**
 广告详情页关闭回调
 */
- (void)fn_onlyNativeAdDetailViewClosed;


/**
 当点击应用下载或者广告调用系统程序打开时调用
 */
- (void)fn_onlyNativeAdViewApplicationWillEnterBackground;


@end


@interface FNOnlyFeedAds : NSObject

@property (nonatomic, weak) id<FNOnlyFeedAdsDelegate> delegate;


/**
 请求视频的时长下限，视频时长有效值范围为[5,60]。
 以下两种情况会使用系统默认的最小值设置，1:不设置  2:minVideoDuration大于maxVideoDuration
*/
@property (nonatomic) NSInteger minVideoDuration;

/**
 请求视频的最大时长，视频时长有效值范围为[5,60]。
 */
@property (nonatomic) NSInteger maxVideoDuration;


+ (instancetype)shareFnOnlyFeed;


/**初始化SDK*/
/**params adsID 由平台分配初始化ID*/
/**params adsID 由平台分配广告位ID*/
/**params count  一次拉取广告的个数
 */
- (void)loadFnFeedAd:(NSString *)appid  ADS:(NSString *)adsID loadCount:(int)count;

@end

NS_ASSUME_NONNULL_END
