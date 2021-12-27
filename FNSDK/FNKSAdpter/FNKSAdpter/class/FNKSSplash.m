//
//  FNKSSplash.m
//  FNAD
//
//  Created by ALAN on 2021/7/19.
//

#import "FNKSSplash.h"


static NSString * const FNSPLASHNOTIFICATIONNAME = @"6-KS-Splash";
@interface FNKSSplash()<KSSplashAdViewDelegate>

@property (nonatomic, strong) KSSplashAdView *splashKSAdView;
@property (nonatomic,strong)UIViewController *rootVC;
@property (nonatomic,copy)NSString *isKSSplashNotificationString;

@property (atomic,strong)UIView *bottomView;

@end

@implementation FNKSSplash


- (void)register_notification:(id)obj params:(NSDictionary *)adParams {
    
    self.isKSSplashNotificationString = adParams[@"notificationName"];
    
    // 调用当前类的类持有监听
    [[NSNotificationCenter defaultCenter] addObserver:obj selector:@selector(ad_callback:) name:self.isKSSplashNotificationString object:nil];
    //self监听进行广告显示
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(ad_showcallback:) name:FNSPLASHNOTIFICATIONNAME object:nil];
    //拉去开屏广告
    [self laodSplashAd:adParams];
}


/// 广告回调发送通知,抛出到一级调用
/// @param paramsDic 传出去的参数
- (void)post_notifaction:(NSDictionary *)paramsDic {
    [[NSNotificationCenter defaultCenter] postNotificationName:self.isKSSplashNotificationString object:@{
        @"ad_channle": FNSPLASHNOTIFICATIONNAME,
        @"ad_type": @"splash",
        @"ad_status": paramsDic[@"ad_status"],
        @"ad_error": paramsDic[@"ad_error"]?paramsDic[@"ad_error"]:@""
}];
}


#pragma mark 加载KS开屏广告
- (void)laodSplashAd:(NSDictionary *)adTypeNumDic {
   
    if ([adTypeNumDic[@"btm"] isKindOfClass:[UIView class]])
        self.bottomView = adTypeNumDic[@"btm"];
    
    self.rootVC = adTypeNumDic[@"VC"];
    self.splashKSAdView = [[KSSplashAdView alloc] initWithPosId:adTypeNumDic[@"thirdAdsId"]];
    self.splashKSAdView.delegate = self;
    UIWindow *fK = [[UIApplication sharedApplication] keyWindow];
    self.splashKSAdView.rootViewController = fK.rootViewController;
   
    if (self.bottomView) {
       
        CGRect frame = [UIScreen mainScreen].bounds;
        CGSize size = CGSizeMake([UIScreen mainScreen].bounds.size.width, frame.size.height - self.bottomView.frame.size.height);

        frame.size = size;
        self.splashKSAdView.frame = frame;
        
    }else
    {
        self.splashKSAdView.frame = [UIScreen mainScreen].bounds;
    }
    
    
    [self.splashKSAdView loadAdData];
    
}


- (void)showKSSplash {
    UIWindow *fK = [[UIApplication sharedApplication] keyWindow];
    
    if (self.bottomView) {
    
    CGRect frame = CGRectMake(0, CGRectGetHeight(self.splashKSAdView.frame), self.splashKSAdView.frame.size.width, self.bottomView.frame.size.height);
    self.bottomView.frame = frame;
    [self.splashKSAdView addSubview:self.bottomView];
        
 
    }
    
    [self.splashKSAdView showInView:fK];

}

/// 显示广告观察者回调
- (void)ad_showcallback:(NSNotification *)notice {
    [self showKSSplash];
}


#pragma mark ----------------KSSplashAdDelegate----------------------
/// 启动广告素材加载，准备显示
- (void)ksad_splashAdContentDidLoad:(KSSplashAdView *)splashAdView {
    [self post_notifaction:@{
                              @"ad_status":@"SPLASH_LOADED"}];
}


/// splash ad clicked
- (void)ksad_splashAd:(KSSplashAdView *)splashAdView didClick:(BOOL)inMiniWindow{
    // 用于回调发送通知
     [self post_notifaction:@{
                               @"ad_status":@"SPLASH_CLICK"}];
}


/// 由用户关闭启动广告（缩小模式）（没有后续回调，在此处删除并释放 KSSplashAdView）
- (void)ksad_splashAdDidClose:(KSSplashAdView *)splashAdView{
    // 用于回调发送通知
     [self post_notifaction:@{@"ad_status":@"SPLASH_CLOSE"}];
  
}


/// 启动广告确实可见
- (void)ksad_splashAdDidVisible:(KSSplashAdView *)splashAdView{
    // 用于回调发送通知
     [self post_notifaction:@{@"ad_status":@"SPLASH_DISPLAYSUC"}];
}


/// 启动广告播放完成并自动关闭（无后续回调，在此处删除并释放 KSSplashAdView）
- (void)ksad_splashAdDidAutoDismiss:(KSSplashAdView *)splashAdView{
    // 用于回调发送通知
     [self post_notifaction:@{@"ad_status":@"SPLASH_CLOSE"}];
    [self removeSplash];
}


 /// 启动广告（素材）加载失败
- (void)ksad_splashAd:(KSSplashAdView *)splashAdView didFailWithError:(NSError *)error {
    // 用于回调发送通知
    [self post_notifaction:@{@"ad_status":@"SPLASH_FAIL",@"ad_error":error}];
//    NSLog(@"%@",error);
    [self removeSplash];
}


///  * splash ad skipped
///   release KSSplashAdView here
/// @param splashAdView <#splashAdView description#>
/// @param playDuration <#playDuration description#>
- (void)ksad_splashAd:(KSSplashAdView *)splashAdView didSkip:(NSTimeInterval)playDuration {
    // 用于回调发送通知
     [self post_notifaction:@{@"ad_status":@"SPLASH_CLOSE"}];
        [self removeSplash];
}


///  splash ad close conversion viewcontroller (no subsequent callbacks, remove &
///   release KSSplashAdView here)
/// @param splashAdView <#splashAdView description#>
/// @param interactType <#interactType description#>
- (void)ksad_splashAdDidCloseConversionVC:(KSSplashAdView *)splashAdView interactionType:(KSAdInteractionType)interactType {
    // 用于回调发送通知
     [self post_notifaction:@{@"ad_status":@"SPLASH_CLOSE"}];
        [self removeSplash];
    [self removeSplash];
}


/// 移除视图
- (void)removeSplash {
        
    [self.splashKSAdView removeFromSuperview];
    self.splashKSAdView = nil;
    self.bottomView = nil;
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}

@end
