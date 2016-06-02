# Ti.PayPal




Summary
---------------
Ti.PayPal is an open-source project to support the PayPal Android-SDK 2.x in Appcelerator's Titanium Mobile. The module currently supports the following API's:
- [x] Simple Payments
- [x] Future Payments
- [x] Merchant Configuration

Attention: is still under work!

Requirements
---------------
- Titanium Mobile SDK 5.2.2.GA or later
- Android API 22 or later

Download + Setup
---------------

### Setup
Unpack the module and place it inside the `modules/iphone/` folder of your project.
Edit the modules section of your `tiapp.xml` file to include this module:
```xml
<modules>
<module platform="android">ti.paypal</module>
</modules>
```

Initialize the module by setting the PayPal credentials which you can get from [here](https://developer.paypal.com).
```javascript
var PayPal = require("ti.paypal");
PayPal.initialize({
    clientIdSandbox: "<YOUR_CLIENT_ID_SANDBOX>",
    clientIdProduction: "<YOUR_CLIENT_ID_PRODUCTION>",
    environment: PayPal.ENVIRONMENT_SANDBOX // or: ENVIRONMENT_PRODUCTION
});
```

Alternativly you can use global properties in tiapp.xml :  PAYPAL_CLIENT_ID_SANDBOX and PAYPAL_CLIENT_ID_PRODUCTION. In this case need only:
For ENVIRONMENT you can set:
~~~
Ti.App.Properties.setString("PAYPAL_ENVIRONMENT","PRODUCTION"); // or "SANDBOX"
~~~

~~~
var PayPal = require("ti.paypal");
    PayPal.initialize();
});
~~~

Features
--------------------------------
#### Simple Payment
A simple payment is used for do instant payments with items you define. Watch the events for updates on your transaction.

```javascript

var item1 = PayPal.createPaymentItem({
    name: "My item",
    price: 23.99,
    sku: "my-item",
    quantity: 1,
    currency: "USD" // Any ISO-4217
});

var configuration = PayPal.createConfiguration({
    merchantName: "John Doe",
    merchantPrivacyPolicyURL: "http://google.com",
    merchantUserAgreementURL: "http://google.com",
    locale: "en" // Any ISO 639-1
});

var payment = PayPal.createPayment({
    // Required
    configuration: configuration,
    currencyCode: "USD",
    amount: 23.99, // Has to match the amount of your items if you set them
    shortDescription: "Your shopping trip at FooBar",
    intent: PayPal.PAYMENT_INTENT_SALE, // or: PAYMENT_INTENT_AUTHORIZE, PAYMENT_INTENT_ORDER

    // Optional, you can also just specify the amount
    items: [item1]
});

payment.addEventListener("paymentDidCancel", function(e) {
    Ti.API.warn("paymentDidCancel");
});

payment.addEventListener("paymentWillComplete", function(e) {
    Ti.API.warn("paymentWillComplete");
});

payment.addEventListener("paymentDidComplete", function(e) {
    Ti.API.warn("paymentDidComplete");
});

payment.show();	
```

#### Future Payment
A future payment is used to ask the buyer for the permission to charge his account later.

```javascript
var configuration = PayPal.createConfiguration({
    merchantName: "John Doe",
    merchantPrivacyPolicyURL: "http://google.com",
    merchantUserAgreementURL: "http://google.com",
    locale: "en"
});

var payment = PayPal.createFuturePayment({
configuration: configuration
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
