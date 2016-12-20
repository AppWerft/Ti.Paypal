# Ti.PayPal

![](https://raw.githubusercontent.com/AppWerft/Ti.Paypal/master/documentation/Screenshot_20160602-170117.png)
![](https://raw.githubusercontent.com/AppWerft/Ti.Paypal/master/documentation/Screenshot_20160602-170314.png)
![](https://raw.githubusercontent.com/AppWerft/Ti.Paypal/master/documentation/Screenshot_20160602-171951.png)



Summary
---------------
Ti.PayPal is an open-source project to support the PayPal Android-SDK 2.x in Appcelerator's Titanium Mobile. The module currently supports the following API's:
- [x] Simple Payments
- [x] Future Payments
- [x] Merchant Configuration

Attention: is still under work!  

__This interface und README is a copy of [Hans's Ti.PayPal](https://github.com/hansemannn/ti.paypal) for iOS.__

Requirements
---------------
- Titanium Mobile SDK 5.2.2.GA or later
- Android API 22 or later

Download + Setup
---------------

### Setup
Unpack the module and place it inside the `modules/android/` folder of your project.
Edit the modules section of your `tiapp.xml` file to include this module:
```xml
<modules>
<module platform="android">de.appwerft.paypal</module>
</modules>
```

Add this into your application section of Manifest:
```xml
<service android:name="com.paypal.android.sdk.payments.PayPalService" android:exported="false"/>
<activity android:name="com.paypal.android.sdk.payments.PaymentActivity"/>
<activity android:name="com.paypal.android.sdk.payments.LoginActivity"/>
<activity android:name="com.paypal.android.sdk.payments.PaymentMethodActivity"/>
<activity android:name="com.paypal.android.sdk.payments.PaymentConfirmActivity"/>
```

Optionally you can modify the theming (suppressing/coloring actionbar and/or navigationbar)

If you have only one instance of PayPal billing in you app, the you can put the PayPal credentials into tiapp.xml:

~~~
<property name="PAYPAL_CLIENT_ID_SANDBOX" type="string">AYXg7yzeFQG08l*************zHkfoBOCtoB50KeooDq2</property>
<property name="PAYPAL_CLIENT_ID_PRODUCTION" type="string">FQG0****************</property>
<property name="PAYPAL_ENVIRONMENT" type="string">PRODUCTION</property>
~~~

In this case you can simple instantiate with:
~~~
var PayPal = require("ti.paypal");
~~~

Alternativly can you set the creds at runtime: 
```javascript
var PayPal = require("de.appwerft.paypal");
PayPal.initPayment({
    clientIdSandbox: "AYXg7yzeFQG08l*************zHkfoBOCtoB50KeooDq2",
    clientIdProduction: "AYXg7yzeFQG08l*************zHkfoBOCtoB50KeooDq2",
    environment: PayPal.ENVIRONMENT_SANDBOX // or: ENVIRONMENT_PRODUCTION
});
```
And you can mix, i.e. Ids in tiapp.xml and the select at runtime.

Features
--------------------------------
#### Simple Payment
A simple payment is used for do instant payments with items you define. Watch the events for updates on your transaction.

```javascript


var configuration = PayPal.createConfiguration( {
    merchantName: "John Doe",
    merchantPrivacyPolicyURL: "http://google.com",
    merchantUserAgreementURL: "http://google.com",
    locale: "en" // Any ISO 639-1
    },
);


var payment = PayPal.createPayment({
    // Required
    configuration: configuration,
    currencyCode: "USD",
    amount: 23.99, // Has to match the amount of your items if you set them
    shortDescription: "Your shopping trip at FooBar",
    intent: PayPal.PAYMENT_INTENT_SALE, // or: PAYMENT_INTENT_AUTHORIZE, PAYMENT_INTENT_ORDER

    // Optional, you can also just specify the amount
    items: [{
        name: "My item",
        price: 23.99,
        sku: "my-item",
        quantity: 1,
        currency: "USD" // Any ISO-4217
    }],
    shipping : 10.0
    tax : 123,10
});

payment.addEventListener("paymentDidCancel", function(e) {
    Ti.API.warn("paymentDidCancel");
});


payment.addEventListener("paymentDidComplete", function(e) {
    Ti.API.warn("paymentDidComplete");
});

payment.showPaymentOverLay();	
```

Or compact:
~~~


var payment = PayPal.createPayment({
// Required
    configuration : {
        merchantName: "John Doe",
        merchantPrivacyPolicyURL: "http://google.com",
        merchantUserAgreementURL: "http://google.com",
        locale: "en" // Any ISO 639-1
    },
    currencyCode: "USD",
    amount: 23.99, // Has to match the amount of your items if you set them
    shortDescription: "Your shopping trip at FooBar",
    intent: PayPal.PAYMENT_INTENT_SALE, // or: PAYMENT_INTENT_AUTHORIZE, PAYMENT_INTENT_ORDER
    items: [{
        name: "Titanium workshop",
        price: 900.00,
        sku: "12345",
        quantity: 1,
        currency: "EUR"     
    }],
    shipping : 10.0
    tax : 123,10
});

payment.addEventListener("paymentDidCancel", function(e) {
Ti.API.warn("paymentDidCancel");
});

payment.addEventListener("paymentDidComplete", function(e) {
Ti.API.warn("paymentDidComplete");
});
payment.addEventListener("authorization", function(e) {
});
payment.showPaymentOverlay();	
~~~


#### Future Payment
A future payment is used to ask the buyer for the permission to charge his account later.

```javascript;

var payment = PayPal.createPayment({
    configuration: {
        merchantName: "John Doe",
        merchantPrivacyPolicyURL: "http://google.com",
        merchantUserAgreementURL: "http://google.com",
        locale: "en"
    },
    futurePayment : true
});

payment.addEventListener("futurePaymentDidCancel", function(e) {
    Ti.API.warn("futurePaymentDidCancel");
});

payment.addEventListener("futurePaymentWillComplete", function(e) {
    Ti.API.warn("futurePaymentWillComplete");
});

payment.addEventListener("futurePaymentDidComplete", function(e) {
    Ti.API.warn("futurePaymentDidComplete");
});

payment.show();	
```

#### Profile Sharing
> Note: This API is currently work in progress!
Profile sharing is used to share a user profile by defining different scopes that can be authorized. Available Scopes:

- [x] SCOPE_FUTURE_PAYMENTS
- [x] SCOPE_PROFILE
- [x] SCOPE_OPEN_ID
- [x] SCOPE_PAYPAL_ATTRIBUTES
- [x] SCOPE_EMAIL
- [x] SCOPE_ADDRESS
- [x] SCOPE_PHONE

```javascript
var configuration = PayPal.createConfiguration({
merchantName: "John Doe",
merchantPrivacyPolicyURL: "http://google.com",
merchantUserAgreementURL: "http://google.com",
locale: "en"
});

var profile = PayPal.createProfileSharing({
configuration: configuration,
scopes: [PayPal.SCOPE_PROFILE, PayPal.SCOPE_EMAIL]
});

profile.addEventListener("profileSharingDidCancel", function(e) {
Ti.API.warn("profileSharingDidCancel");
});

profile.addEventListener("profileSharingWillLogIn", function(e) {
Ti.API.warn("profileSharingWillLogIn");
});

profile.addEventListener("profileSharingDidLogIn", function(e) {
Ti.API.warn("profileSharingDidLogIn");
});

profile.show();
```

#### Example
For a full example covering all API's, check the demo in `android/example/app.js`.

Author
---------------
Rainer Schleevoigt ([@appwerft](https://twitter.com/appwerft) / [Web](http://hamburger-appwerft.de))

License
---------------
Apache 2.0

Contributing
---------------
Code contributions are greatly appreciated, please submit a new [pull request](https://github.com/hansemannn/ti.paypal/pull/new/master)!