//
//  FNKSSDKAdpter.m
//  FNAD
//
//  Created by ALAN on 2021/7/27.
//

#import "FNKSSDKAdpter.h"

@implementation FNKSSDKAdpter

- (void)initialize_SDK:(NSDictionary *)paramsAd {
    
    NSString *thirdAppId = paramsAd[@"thirdAppId"];
    ///初始KS化广告sdk
    [KSAdSDKManager setAppId:thirdAppId];
}
@end
