//
//  FNInitializeSplash.h
//  FNAD
//
//  Created by ALAN on 2021/5/8.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "FNLoadSplashAdDelegate.h"


NS_ASSUME_NONNULL_BEGIN

@interface FNInitializeSplash : NSObject

/**自定义底部视图*/
@property(nonatomic,strong) UIView *bottomView;

/**委托对象*/
@property(nonatomic,weak) id<FNLoadSplashAdDelegate> delegate;


/// 构造方法
/// @param appId 联系商务分配appId
/// @param adsId 联系商务分配adsId
- (instancetype)initWithPlacementId:(NSString *)appId adsId:(NSString *)adsId;


/**loadAndShow*/
- (void)loadFnSplashAd;

@end

NS_ASSUME_NONNULL_END
