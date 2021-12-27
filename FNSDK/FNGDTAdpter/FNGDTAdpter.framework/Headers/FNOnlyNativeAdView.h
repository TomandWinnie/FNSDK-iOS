//
//  FNOnlyNativeAdView.h
//  FNAD
//
//  Created by ALAN on 2021/6/22.
//

#import <UIKit/UIKit.h>
#import "FNOnlyNativeAdDataObject.h"
#import "FNLogoView.h"
#import "FNVideoConfig.h"
#import "FNMediaView.h"
#import "FNOnlySDKDefines.h"


NS_ASSUME_NONNULL_BEGIN

@class FNOnlyNativeAdView;

//视频广告时长Key
extern NSString* const kFNOnlyNativeAdKeyVideoDuration;

@protocol FNOnlyNativeAdViewDelegate <NSObject>

@optional

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


@interface FNOnlyNativeAdView : UIView


/**
 绑定的数据对象
 */
@property (nonatomic, strong) FNOnlyNativeAdDataObject *dataObject;

/**
 视频广告的媒体View，绑定数据对象后自动生成，可自定义布局
 */
@property (nonatomic, strong) FNMediaView *mediaView;

/**
 腾讯广告 LogoView，自动生成，可自定义布局
 */
@property (nonatomic, strong) FNLogoView *logoView;

/**
 广告 View 时间回调对象
 */
@property (nonatomic, weak) id<FNOnlyNativeAdViewDelegate> delegate;

/*
 *  viewControllerForPresentingModalView
 *  详解：开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
 */
@property (nonatomic, weak) UIViewController *viewController;


/**
 获取控件view对象

 @param frameViews NSArray对象存放View
 */
- (void)fn_onlyGetAllViews:(NSArray<UIView *> *)frameViews;


/**
 自渲染2.0视图注册方法
 
 @param dataObject 数据对象，必传字段
 @param clickableViews 可点击的视图数组，此数组内的广告元素才可以响应广告对应的点击事件
 */
- (void)registerDataObject:(FNOnlyNativeAdDataObject *)dataObject
            clickableViews:(NSArray<UIView *> *)clickableViews;


/**
 自渲染2.0视图注册方法
 @param dataObject 数据对象，必传字段
 @param clickableViews 可点击的视图数组，此数组内的广告元素才可以响应广告对应的点击事件
 @param customClickableViews 可点击的视图数组，与clickableViews的区别是：在视频广告中当dataObject中的videoConfig的detailPageEnable为YES时，点击后直接进落地页而非视频详情页，除此条件外点击行为与clickableViews保持一致
 */
- (void)registerDataObject:(FNOnlyNativeAdDataObject *)dataObject
            clickableViews:(NSArray<UIView *> *)clickableViews customClickableViews:(NSArray <UIView *> *)customClickableViews;

/**
 注册可点击的callToAction视图的方法
 建议开发者使用FNOnlyNativeAdDataObject中的callToAction字段来创建视图，并取代自定义的下载或打开等button,
 调用此方法之前必须先调用registerDataObject:clickableViews
 @param callToActionView CTA视图, 系统自动处理点击事件
 */
- (void)registerClickableCallToActionView:(UIView *)callToActionView;

/**
 注销数据对象，在 tableView、collectionView 等场景需要复用 FNOnlyNativeAdView 时，
 需要在合适的时机，例如 cell 的 prepareForReuse 方法内执行 unregisterDataObject 方法，
 将广告对象与 FNOnlyNativeAdView 解绑，具体可参考示例 demo 的 UnifiedNativeAdBaseTableViewCell 类
 */
- (void)unregisterDataObject;

@end

NS_ASSUME_NONNULL_END
