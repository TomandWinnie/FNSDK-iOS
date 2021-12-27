//
//  FNInitalizeInterstitial.h
//  FNAD
//
//  Created by ALAN on 2021/5/11.
//

#import <Foundation/Foundation.h>
#import "FNLoadInterstitialAdDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@interface FNInitalizeInterstitial : NSObject

/**
 *  委托对象
 */
@property(nonatomic,weak) id<FNLoadInterstitialAdDelegate> delegate;


/**初始化当前类*/
+ (instancetype)shareFnINterstitial;

/**初始化SDK*/
/**params adsID 由平台分配初始化平台ID*/
/**params adsID 由平台分配广告位ID*/
- (void)loadFnInterstitialAd:(NSString *)appid  ADS:(NSString *)adsID;


@end

NS_ASSUME_NONNULL_END
