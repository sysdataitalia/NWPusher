//
//  NWPusher.h
//  Pusher
//
//  Copyright (c) 2012 noodlewerk. All rights reserved.
//

typedef enum {
    kNWPusherResultSuccess = -1,
    // APN error codes
    kNWPusherResultAPNNoErrorsEncountered = 0,
    kNWPusherResultAPNProcessingError = 1,
    kNWPusherResultAPNMissingDeviceToken = 2,
    kNWPusherResultAPNMissingTopic = 3,
    kNWPusherResultAPNMissingPayload = 4,
    kNWPusherResultAPNInvalidTokenSize = 5,
    kNWPusherResultAPNInvalidTopicSize = 6,
    kNWPusherResultAPNInvalidPayloadSize = 7,
    kNWPusherResultAPNInvalidToken = 8,
    kNWPusherResultAPNUnknownReason = 9,
    kNWPusherResultAPNShutdown = 10,
    // Pusher error codes
    kNWPusherResultEmptyPayload = 101,
    kNWPusherResultInvalidPayload = 102,
    kNWPusherResultEmptyToken = 103,
    kNWPusherResultInvalidToken = 104,
    kNWPusherResultPayloadTooLong = 105,
    kNWPusherResultUnableToReadResponse = 106,
    kNWPusherResultUnexpectedResponseCommand = 107,
    kNWPusherResultUnexpectedResponseLength = 108,
    kNWPusherResultUnexpectedTokenLength = 109,
    kNWPusherResultIDOutOfSync = 110,
    // Socket error codes
    kNWPusherResultIOConnectFailed = 201,
    kNWPusherResultIOConnectSSLContext = 202,
    kNWPusherResultIOConnectSocketCallbacks = 203,
    kNWPusherResultIOConnectSSL = 204,
    kNWPusherResultIOConnectPeerDomain = 205,
    kNWPusherResultIOConnectAssignCertificate = 206,
    kNWPusherResultIOConnectSSLHandshakeConnection = 207,
    kNWPusherResultIOConnectSSLHandshakeAuthentication = 208,
    kNWPusherResultIOConnectSSLHandshakeError = 209,
    kNWPusherResultIOReadDroppedByServer = 210,
    kNWPusherResultIOReadConnectionError = 211,
    kNWPusherResultIOReadConnectionClosed = 212,
    kNWPusherResultIOReadError = 213,
    kNWPusherResultIOWriteDroppedByServer = 214,
    kNWPusherResultIOWriteConnectionError = 215,
    kNWPusherResultIOWriteConnectionClosed = 216,
    kNWPusherResultIOWriteError = 217,
    // Tools error codes
    kNWPusherResultCertificateInvalid = 301,
    kNWPusherResultCertificatePrivateKeyMissing = 302,
    kNWPusherResultCertificateCreateIdentity = 303,
    kNWPusherResultCertificateNotFound = 304,
    kNWPusherResultPKCS12EmptyData = 305,
    kNWPusherResultPKCS12InvalidData = 306,
    kNWPusherResultPKCS12NoItems = 307,
    kNWPusherResultPKCS12NoIdentity = 308,
} NWPusherResult;


@interface NWPusher : NSObject

#if !TARGET_OS_IPHONE
- (NWPusherResult)connectWithCertificateRef:(SecCertificateRef)certificate sandbox:(BOOL)sandbox;
#endif
- (NWPusherResult)connectWithIdentityRef:(SecIdentityRef)identity sandbox:(BOOL)sandbox;
- (NWPusherResult)connectWithPKCS12Data:(NSData *)data password:(NSString *)password sandbox:(BOOL)sandbox;
- (NWPusherResult)pushPayloadString:(NSString *)payload token:(NSString *)token;
- (NWPusherResult)pushPayloadString:(NSString *)payload token:(NSString *)token identifier:(NSUInteger)identifier expires:(NSDate *)expires;
- (NWPusherResult)pushPayloadData:(NSData *)payload tokenData:(NSData *)token;
- (NWPusherResult)pushPayloadData:(NSData *)payload tokenData:(NSData *)token identifier:(NSUInteger)identifier expires:(NSDate *)expires;
- (NWPusherResult)fetchFailedIdentifier:(NSUInteger *)identifier;
- (void)connectWithPKCS12Data:(NSData *)data password:(NSString *)password sandbox:(BOOL)sandbox block:(void(^)(NWPusherResult response))block;
- (NSUInteger)pushPayloadString:(NSString *)payload token:(NSString *)token expires:(NSDate *)expires block:(void(^)(NWPusherResult response))block;
- (void)disconnect;
+ (NSString *)stringFromResult:(NWPusherResult)result;

+ (NSData *)dataFromHex:(NSString *)hex;
+ (NSString *)hexFromData:(NSData *)data;

@end
