/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2011 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 *
 * Warning: This file is GENERATED, and should not be modified
 */
var bootstrap = kroll.NativeModule.require("bootstrap"),
	invoker = kroll.NativeModule.require("invoker"),
	Titanium = kroll.binding("Titanium").Titanium;

function moduleBootstrap(moduleBinding) {
	function lazyGet(object, binding, name, namespace) {
		return bootstrap.lazyGet(object, binding,
			name, namespace, moduleBinding.getBinding);
	}

	var module = moduleBinding.getBinding("ti.paypal.PaypalModule")["Paypal"];
	var invocationAPIs = module.invocationAPIs = [];
	module.apiName = "Paypal";

	function addInvocationAPI(module, moduleNamespace, namespace, api) {
		invocationAPIs.push({ namespace: namespace, api: api });
	}

		addInvocationAPI(module, "Paypal", "Paypal", "createPayment");
	addInvocationAPI(module, "Paypal", "Paypal", "createConfiguration");
	addInvocationAPI(module, "Paypal", "Paypal", "createPaymentItem");

			if (!("__propertiesDefined__" in module)) {		
		Object.defineProperties(module, {
			"Configuration": {
				get: function() {
					var Configuration = lazyGet(this, "ti.paypal.ConfigurationProxy", "Configuration", "Configuration");
					return Configuration;
				},
				configurable: true
			},
			"PaymentItem": {
				get: function() {
					var PaymentItem = lazyGet(this, "ti.paypal.PaymentItemProxy", "PaymentItem", "PaymentItem");
					return PaymentItem;
				},
				configurable: true
			},
			"Payment": {
				get: function() {
					var Payment = lazyGet(this, "ti.paypal.PaymentProxy", "Payment", "Payment");
					return Payment;
				},
				configurable: true
			},
		
		});
		module.constructor.prototype.createPayment = function() {
			return new module.Payment(arguments);
		}
		module.constructor.prototype.createConfiguration = function() {
			return new module.Configuration(arguments);
		}
		module.constructor.prototype.createPaymentItem = function() {
			return new module.PaymentItem(arguments);
		}
		}
		module.__propertiesDefined__ = true;
		return module;

}
exports.bootstrap = moduleBootstrap;
