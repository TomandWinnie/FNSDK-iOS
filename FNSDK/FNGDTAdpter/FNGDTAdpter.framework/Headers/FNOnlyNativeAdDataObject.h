//
//  FNOnlyNativeAdDataObject.h
//  FNAD
//
//  Created by ALAN on 2021/6/18.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "FNVideoConfig.h"

NS_ASSUME_NONNULL_BEGIN


typedef NS_ENUM(NSInteger, FNVastAdEventType) {
    FNVastAdEventTypeUnknow,
    FNVastAdEventTypeLoaded,
    FNVastAdEventTypeStarted,
    FNVastAdEventTypeFirstQuartile,
    FNVastAdEventTypeMidPoint,
    FNVastAdEventTypeThirdQuartile,
    FNVastAdEventTypeComplete,
    FNVastAdEventTypeAllAdsComplete,
    FNVastAdEventTypeExposed,
    FNVastAdEventTypeClicked,
};

@interface FNOnlyNativeAdDataObject : NSObject


/**
 广告标题
 */
@property (nonatomic, copy) NSString *title;

/**
 广告描述
 */
@property (nonatomic, copy) NSString *desc;

/**
 广告大图Url
 */
@property (nonatomic, copy) NSString *imageUrl;

/**
 素材宽度，单图广告代表大图 imageUrl 宽度、多图广告代表小图 mediaUrlList 宽度
 */
@property (nonatomic, assign) NSInteger imageWidth;

/**
 素材高度，单图广告代表大图 imageUrl 高度、多图广告代表小图 mediaUrlList 高度
 */
@property (nonatomic, assign) NSInteger imageHeight;

/**
 应用类广告App 图标Url
 */
@property (nonatomic, copy) NSString *iconUrl;

/**
 三小图广告的图片Url集合
 */
@property (nonatomic, copy) NSArray *mediaUrlList;

/**
 应用类广告的星级（5星制度）
 */
@property (nonatomic, assign) CGFloat appRating;

/**
 应用类广告的价格
 */
@property (nonatomic, strong) NSNumber *appPrice;

/**
 是否为应用类广告
 */
@property (nonatomic, assign) BOOL isAppAd;

/**
 是否为视频广告
 */
@property (nonatomic, assign) BOOL isVideoAd;

/**
 是否为三小图广告
 */
@property (nonatomic, assign) BOOL isThreeImgsAd;

/**
 返回广告的eCPM，单位：分
 
 @return 成功返回一个大于等于0的值，-1表示无权限或后台出现异常
 */
@property (nonatomic, assign) NSInteger eCPM;

/**
 返回广告的eCPM等级
 
 @return 成功返回一个包含数字的string，@""或nil表示无权限或后台异常
 */
@property (nonatomic, copy) NSString *eCPMLevel;

/**
 广告对应的CTA文案，自定义CTA视图时建议使用此字段
 广告对应的callToAction文案，比如“立即预约”或“电话咨询”, 自定义callToAction视图时建议使用此字段

 该字段在部分广告类型中可能为空
 */
@property (nonatomic, copy) NSString *callToAction;

/**
返回广告是否可以跳过，用于做前贴片场景

@return YES 表示可跳过、NO 表示不可跳过
*/
@property (nonatomic, assign) BOOL skippable;

/**
 视频广告播放配置
 */
@property (nonatomic, strong) FNVideoConfig *videoConfig;

/**
 * 视频广告时长，单位 ms
 */
@property (nonatomic, assign) CGFloat duration;

/**
 *  VAST Tag Url，可能为空。
 */
@property (nonatomic, copy) NSString *vastTagUrl;

/**
 * VAST Content，可能为空。
 */
@property (nonatomic, copy) NSString *vastContent;

/**
 * 是否为 VAST 广告
 */
@property (nonatomic, assign) BOOL isVastAd;

/**
 判断两个自渲染2.0广告数据是否相等

 @param dataObject 需要对比的自渲染2.0广告数据对象
 @return YES or NO
 */
- (BOOL)equalsAdData:(FNOnlyNativeAdDataObject *)dataObject;


@end

NS_ASSUME_NONNULL_END
