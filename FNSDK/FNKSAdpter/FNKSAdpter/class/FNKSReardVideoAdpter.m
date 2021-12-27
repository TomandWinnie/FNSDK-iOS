//
//  FNKSReardVideoAdpter.m
//  FNAD
//
//  Created by ALAN on 2021/7/26.
//

#import "FNKSReardVideoAdpter.h"


static NSString * const FNREARDVIDEONOTIFICATIONNAME = @"6-KS-ReardVideo";
@interface FNKSReardVideoAdpter()<KSRewardedVideoAdDelegate>

@property (nonatomic, strong) KSRewardedVideoAd *ksRewardedVideoAd;
@property (nonatomic,strong)UIViewController *rootVC;
@property (nonatomic,copy)NSString *isKSNotificationString;
@end



@implementation FNKSReardVideoAdpter


- (void)register_notification:(id)obj params:(NSDictionary *)adParams {
    
    self.isKSNotificationString = adParams[@"notificationName"];
    
    // 调用当前类的类持有监听,用户广告回调方法发送通知
    [[NSNotificationCenter defaultCenter] addObserver:obj selector:@selector(ad_callback:) name:self.isKSNotificationString object:nil];
    
    //self监听进行广告显示,用户加载成功发送通知进行广告显示
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(ad_showcallback:) name:FNREARDVIDEONOTIFICATIONNAME object:nil];
    
    //拉去开屏广告
    [self laodInterstitialAd:adParams];
}


/// 广告回调方法发送通知,抛出到一级调用
/// @param paramsDic 传出去的参数
- (void)post_notifaction:(NSDictionary *)paramsDic {
    [[NSNotificationCenter defaultCenter] postNotificationName:self.isKSNotificationString object:@{
            @"ad_channle": FNREARDVIDEONOTIFICATIONNAME,
            @"ad_type": @"reardVideo",
            @"ad_status": paramsDic[@"ad_status"],
            @"ad_error": paramsDic[@"ad_error"]?paramsDic[@"ad_error"]:@"",
            @"isCompeltedView":@(NO)
    }];
}


/// 加载KS激励视屏广告
- (void)laodInterstitialAd:(NSDictionary *)adTypeNumDic  {
    
    self.rootVC = adTypeNumDic[@"VC"];
    /// 激励视频广告
    KSRewardedVideoModel *model = [KSRewardedVideoModel new];
    model.userId = @"123234";
    model.extra = @"test extra";
    self.ksRewardedVideoAd = [[KSRewardedVideoAd alloc] initWithPosId:adTypeNumDic[@"thirdAdsId"] rewardedVideoModel:model];
    self.ksRewardedVideoAd.delegate = self;
    /// 0竖屏;1横屏
    self.ksRewardedVideoAd.showDirection = 0;
    [self.ksRewardedVideoAd loadAdData];
   
}


/// 显示广告观察者回调
- (void)ad_showcallback:(NSNotification *)notice {
    [self showKSReardVideoAd];
}


/// 显示广告
- (void)showKSReardVideoAd {
    if (self.ksRewardedVideoAd.isValid) {
        [self.ksRewardedVideoAd showAdFromRootViewController:self.rootVC];
    }
}


#pragma mark-----------------KSRewardedVideoAdDelegate-------------------
/// 加载成功
- (void)rewardedVideoAdVideoDidLoad:(KSRewardedVideoAd *)rewardedVideoAd {
    /// 这里能获取到ecpm
    [self post_notifaction:@{@"ad_status":@"REWARDVIDEO_LOADED"}];
}


/// 当视频广告位已显示时调用此方法。
- (void)rewardedVideoAdDidVisible:(KSRewardedVideoAd *)rewardedVideoAd{
    [self post_notifaction:@{@"ad_status":@"REWARDVIDEO_DISPLAYSUC"}];
}


/// 当视频广告播放完成或发生错误时调用此方法。
- (void)rewardedVideoAdDidPlayFinish:(KSRewardedVideoAd *)rewardedVideoAd didFailWithError:(NSError *_Nullable)error{
    if (error) {
        [self post_notifaction:@{@"ad_status":@"REWARDVIDEO_FAIL",
                                  @"ad_error":error}];
        [self removeNotifacation];
    }
}


///当视频广告素材加载失败时调用此方法。
- (void)rewardedVideoAd:(KSRewardedVideoAd *)rewardedVideoAd didFailWithError:(NSError *_Nullable)error{
    [self post_notifaction:@{@"ad_status":@"REWARDVIDEO_FAIL",
                              @"ad_error":error}];
    [self removeNotifacation];
}


///This method is called when video ad is clicked.
- (void)rewardedVideoAdDidClick:(KSRewardedVideoAd *)rewardedVideoAd{
    [self post_notifaction:@{@"ad_status":@"REWARDVIDEO_CLICK"}];
}


///当用户关闭视频广告时调用此方法。
- (void)rewardedVideoAd:(KSRewardedVideoAd *)rewardedVideoAd hasReward:(BOOL)hasReward{
    
    [self post_notifaction:@{@"ad_status":@"REWARDVIDEO_REWARD"}];
}


/**
 当视频广告即将关闭时调用此方法。
 */
- (void)rewardedVideoAdWillClose:(KSRewardedVideoAd *)rewardedVideoAd{
    // 用于回调发送通知
    [self post_notifaction:@{@"ad_status":@"REWARDVIDEO_CLOSE"}];
    [self removeNotifacation];
}


/**
 当视频广告关闭时调用此方法。
 */
- (void)rewardedVideoAdDidClose:(KSRewardedVideoAd *)rewardedVideoAd{
    
}


/**
 当用户单击跳过按钮时调用此方法。
 */
- (void)rewardedVideoAdDidClickSkip:(KSRewardedVideoAd *)rewardedVideoAd{
    
}

- (void)removeNotifacation {
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}

@end
