//
//  FNKSInterstitial.m
//  FNAD
//
//  Created by ALAN on 2021/7/23.
//

#import "FNKSInterstitial.h"

static NSString * const FNINTERSTITIALNOTIFICATIONNAME = @"6-KS-Interstitial";
@interface FNKSInterstitial()<KSInterstitialAdDelegate>
@property (nonatomic, strong) KSInterstitialAd *ksInterstitialAd;
@property (nonatomic,strong)UIViewController *rootVC;
@property (nonatomic,copy)NSString *isKSInNotificationString;
@end

@implementation FNKSInterstitial


- (void)register_notification:(id)obj params:(NSDictionary *)adParams {
    
    self.isKSInNotificationString = adParams[@"notificationName"];
    
    // 调用当前类的类持有监听,用户广告回调方法发送通知
    [[NSNotificationCenter defaultCenter] addObserver:obj selector:@selector(ad_callback:) name:self.isKSInNotificationString object:nil];
    
    //self监听进行广告显示,用户加载成功发送通知进行广告显示
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(ad_showcallback:) name:FNINTERSTITIALNOTIFICATIONNAME object:nil];
    
    //拉去开屏广告
    [self laodInterstitialAd:adParams];
}


/// 广告回调方法发送通知,抛出到一级调用
/// @param paramsDic 传出去的参数
- (void)post_notifaction:(NSDictionary *)paramsDic {
    [[NSNotificationCenter defaultCenter] postNotificationName:self.isKSInNotificationString object:@{
            @"ad_channle": FNINTERSTITIALNOTIFICATIONNAME,
            @"ad_type": @"interstitial",
            @"ad_status": paramsDic[@"ad_status"],
            @"ad_error": paramsDic[@"ad_error"] ? paramsDic[@"ad_error"]:@""
    }];
}


/// 加载KS插屏广告
- (void)laodInterstitialAd:(NSDictionary *)adTypeNumDic  {
    
    self.rootVC = adTypeNumDic[@"VC"];
    
    // 获取插屏视频广告
    self.ksInterstitialAd = [[KSInterstitialAd alloc] initWithPosId:adTypeNumDic[@"thirdAdsId"] containerSize:self.rootVC.view.bounds.size];
    self.ksInterstitialAd.delegate = self;
    [self.ksInterstitialAd loadAdData];
}


/// 显示广告观察者回调
- (void)ad_showcallback:(NSNotification *)notice {
    [self showKSInterstitial];
}


/// 显示广告
- (void)showKSInterstitial {
    [self.ksInterstitialAd showFromViewController:self.rootVC.navigationController];
}


#pragma mark ------------------- KSInterstitialAdDelegate-----------------
/// 已加载插页式广告数据
- (void)ksad_interstitialAdDidLoad:(KSInterstitialAd *)interstitialAd{
//    NSLog(@"加载成功");
}
/**
 * 插页式广告将可见
 */
- (void)ksad_interstitialAdWillVisible:(KSInterstitialAd *)interstitialAd{
    
}
/**
 * 插页式广告确实可见
 */
- (void)ksad_interstitialAdDidVisible:(KSInterstitialAd *)interstitialAd{
    
}


///插页式广告呈现成功
- (void)ksad_interstitialAdRenderSuccess:(KSInterstitialAd *)interstitialAd{
  //加载成功通知发送和曝光
    // 用于回调发送通知
    [self post_notifaction:@{@"ad_status":@"INTERSTITIAL_LOADED"}];
    [self post_notifaction:@{@"ad_status":@"INTERSTITIAL_DISPLAYSUC"}];
}


/// 插页式广告加载或呈现失败
- (void)ksad_interstitialAdRenderFail:(KSInterstitialAd *)interstitialAd error:(NSError * _Nullable)error{
    // 用于回调发送通知
    if (error) {
     [self post_notifaction:@{@"ad_status":@"INTERSTITIAL_FAIL",
                               @"ad_error":error}];
        [self removeNotifacation];
    }
}


/// interstitial ad did click
- (void)ksad_interstitialAdDidClick:(KSInterstitialAd *)interstitialAd{
    // 用于回调发送通知
     [self post_notifaction:@{@"ad_status":@"INTERSTITIAL_CLICK"}];
}


/// 插页式广告确实关闭了
- (void)ksad_interstitialAdDidClose:(KSInterstitialAd *)interstitialAd{
    // 用于回调发送通知
     [self post_notifaction:@{@"ad_status":@"INTERSTITIAL_CLOSE"}];
    [self removeNotifacation];
}
 

- (void)removeNotifacation {
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}
@end
