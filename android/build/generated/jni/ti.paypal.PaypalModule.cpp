/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2011-2013 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

/** This code is generated, do not edit by hand. **/

#include "ti.paypal.PaypalModule.h"

#include "AndroidUtil.h"
#include "EventEmitter.h"
#include "JNIUtil.h"
#include "JSException.h"
#include "Proxy.h"
#include "ProxyFactory.h"
#include "TypeConverter.h"
#include "V8Util.h"



#include "ti.paypal.PaymentProxy.h"
#include "ti.paypal.ConfigurationProxy.h"
#include "ti.paypal.PaymentItemProxy.h"

#include "org.appcelerator.kroll.KrollModule.h"

#define TAG "PaypalModule"

using namespace v8;

		namespace ti {
		namespace paypal {


Persistent<FunctionTemplate> PaypalModule::proxyTemplate = Persistent<FunctionTemplate>();
jclass PaypalModule::javaClass = NULL;

PaypalModule::PaypalModule(jobject javaObject) : titanium::Proxy(javaObject)
{
}

void PaypalModule::bindProxy(Handle<Object> exports)
{
	if (proxyTemplate.IsEmpty()) {
		getProxyTemplate();
	}

	// use symbol over string for efficiency
	Handle<String> nameSymbol = String::NewSymbol("Paypal");

	Local<Function> proxyConstructor = proxyTemplate->GetFunction();
	Local<Object> moduleInstance = proxyConstructor->NewInstance();
	exports->Set(nameSymbol, moduleInstance);
}

void PaypalModule::dispose()
{
	LOGD(TAG, "dispose()");
	if (!proxyTemplate.IsEmpty()) {
		proxyTemplate.Dispose();
		proxyTemplate = Persistent<FunctionTemplate>();
	}

	titanium::KrollModule::dispose();
}

Handle<FunctionTemplate> PaypalModule::getProxyTemplate()
{
	if (!proxyTemplate.IsEmpty()) {
		return proxyTemplate;
	}

	LOGD(TAG, "GetProxyTemplate");

	javaClass = titanium::JNIUtil::findClass("ti/paypal/PaypalModule");
	HandleScope scope;

	// use symbol over string for efficiency
	Handle<String> nameSymbol = String::NewSymbol("Paypal");

	Handle<FunctionTemplate> t = titanium::Proxy::inheritProxyTemplate(
		titanium::KrollModule::getProxyTemplate()
, javaClass, nameSymbol);

	proxyTemplate = Persistent<FunctionTemplate>::New(t);
	proxyTemplate->Set(titanium::Proxy::inheritSymbol,
		FunctionTemplate::New(titanium::Proxy::inherit<PaypalModule>)->GetFunction());

	titanium::ProxyFactory::registerProxyPair(javaClass, *proxyTemplate);

	// Method bindings --------------------------------------------------------
	DEFINE_PROTOTYPE_METHOD(proxyTemplate, "createConfiguration", PaypalModule::createConfiguration);
	DEFINE_PROTOTYPE_METHOD(proxyTemplate, "initialize", PaypalModule::initialize);
	DEFINE_PROTOTYPE_METHOD(proxyTemplate, "createPaymentItem", PaypalModule::createPaymentItem);

	Local<ObjectTemplate> prototypeTemplate = proxyTemplate->PrototypeTemplate();
	Local<ObjectTemplate> instanceTemplate = proxyTemplate->InstanceTemplate();

	// Delegate indexed property get and set to the Java proxy.
	instanceTemplate->SetIndexedPropertyHandler(titanium::Proxy::getIndexedProperty,
		titanium::Proxy::setIndexedProperty);

	// Constants --------------------------------------------------------------
	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		LOGE(TAG, "Failed to get environment in PaypalModule");
		//return;
	}


		jfieldID fieldPAYMENT_INTENT_AUTHORIZE = env->GetStaticFieldID (javaClass, "PAYMENT_INTENT_AUTHORIZE", "I");
		jint fieldValuePAYMENT_INTENT_AUTHORIZE = env->GetStaticIntField(javaClass, fieldPAYMENT_INTENT_AUTHORIZE);
		DEFINE_NUMBER_CONSTANT(prototypeTemplate, "PAYMENT_INTENT_AUTHORIZE", fieldValuePAYMENT_INTENT_AUTHORIZE);


		jfieldID fieldPAYMENT_INTENT_SALE = env->GetStaticFieldID (javaClass, "PAYMENT_INTENT_SALE", "I");
		jint fieldValuePAYMENT_INTENT_SALE = env->GetStaticIntField(javaClass, fieldPAYMENT_INTENT_SALE);
		DEFINE_NUMBER_CONSTANT(prototypeTemplate, "PAYMENT_INTENT_SALE", fieldValuePAYMENT_INTENT_SALE);


		DEFINE_INT_CONSTANT(prototypeTemplate, "ENVIRONMENT_SANDBOX", 0);

		DEFINE_INT_CONSTANT(prototypeTemplate, "ENVIRONMENT_PRODUCTION", 1);

		jfieldID fieldPAYMENT_INTENT_ORDER = env->GetStaticFieldID (javaClass, "PAYMENT_INTENT_ORDER", "I");
		jint fieldValuePAYMENT_INTENT_ORDER = env->GetStaticIntField(javaClass, fieldPAYMENT_INTENT_ORDER);
		DEFINE_NUMBER_CONSTANT(prototypeTemplate, "PAYMENT_INTENT_ORDER", fieldValuePAYMENT_INTENT_ORDER);



	// Dynamic properties -----------------------------------------------------

	// Accessors --------------------------------------------------------------

	return proxyTemplate;
}

// Methods --------------------------------------------------------------------
Handle<Value> PaypalModule::createConfiguration(const Arguments& args)
{
	LOGD(TAG, "createConfiguration()");
	HandleScope scope;

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		return titanium::JSException::GetJNIEnvironmentError();
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(PaypalModule::javaClass, "createConfiguration", "(Lorg/appcelerator/kroll/KrollDict;)Lcom/paypal/android/sdk/payments/PayPalConfiguration;");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'createConfiguration' with signature '(Lorg/appcelerator/kroll/KrollDict;)Lcom/paypal/android/sdk/payments/PayPalConfiguration;'";
			LOGE(TAG, error);
				return titanium::JSException::Error(error);
		}
	}

	titanium::Proxy* proxy = titanium::Proxy::unwrap(args.Holder());

	if (args.Length() < 1) {
		char errorStringBuffer[100];
		sprintf(errorStringBuffer, "createConfiguration: Invalid number of arguments. Expected 1 but got %d", args.Length());
		return ThrowException(Exception::Error(String::New(errorStringBuffer)));
	}

	jvalue jArguments[1];




	bool isNew_0;
	
	if (!args[0]->IsNull()) {
		Local<Value> arg_0 = args[0];
		jArguments[0].l =
			titanium::TypeConverter::jsObjectToJavaKrollDict(env, arg_0, &isNew_0);
	} else {
		jArguments[0].l = NULL;
	}

	jobject javaProxy = proxy->getJavaObject();
	jobject jResult = (jobject)env->CallObjectMethodA(javaProxy, methodID, jArguments);



	if (!JavaObject::useGlobalRefs) {
		env->DeleteLocalRef(javaProxy);
	}



			if (isNew_0) {
				env->DeleteLocalRef(jArguments[0].l);
			}


	if (env->ExceptionCheck()) {
		Handle<Value> jsException = titanium::JSException::fromJavaException();
		env->ExceptionClear();
		return jsException;
	}

	if (jResult == NULL) {
		return Null();
	}

	Handle<Value> v8Result = titanium::TypeConverter::javaObjectToJsValue(env, jResult);

	env->DeleteLocalRef(jResult);


	return v8Result;

}
Handle<Value> PaypalModule::initialize(const Arguments& args)
{
	LOGD(TAG, "initialize()");
	HandleScope scope;

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		return titanium::JSException::GetJNIEnvironmentError();
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(PaypalModule::javaClass, "initialize", "(Lorg/appcelerator/kroll/KrollDict;)V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'initialize' with signature '(Lorg/appcelerator/kroll/KrollDict;)V'";
			LOGE(TAG, error);
				return titanium::JSException::Error(error);
		}
	}

	titanium::Proxy* proxy = titanium::Proxy::unwrap(args.Holder());

	if (args.Length() < 1) {
		char errorStringBuffer[100];
		sprintf(errorStringBuffer, "initialize: Invalid number of arguments. Expected 1 but got %d", args.Length());
		return ThrowException(Exception::Error(String::New(errorStringBuffer)));
	}

	jvalue jArguments[1];




	bool isNew_0;
	
	if (!args[0]->IsNull()) {
		Local<Value> arg_0 = args[0];
		jArguments[0].l =
			titanium::TypeConverter::jsObjectToJavaKrollDict(env, arg_0, &isNew_0);
	} else {
		jArguments[0].l = NULL;
	}

	jobject javaProxy = proxy->getJavaObject();
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	if (!JavaObject::useGlobalRefs) {
		env->DeleteLocalRef(javaProxy);
	}



			if (isNew_0) {
				env->DeleteLocalRef(jArguments[0].l);
			}


	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException();
		env->ExceptionClear();
	}




	return v8::Undefined();

}
Handle<Value> PaypalModule::createPaymentItem(const Arguments& args)
{
	LOGD(TAG, "createPaymentItem()");
	HandleScope scope;

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		return titanium::JSException::GetJNIEnvironmentError();
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(PaypalModule::javaClass, "createPaymentItem", "(Lorg/appcelerator/kroll/KrollDict;)Lcom/paypal/android/sdk/payments/PayPalItem;");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'createPaymentItem' with signature '(Lorg/appcelerator/kroll/KrollDict;)Lcom/paypal/android/sdk/payments/PayPalItem;'";
			LOGE(TAG, error);
				return titanium::JSException::Error(error);
		}
	}

	titanium::Proxy* proxy = titanium::Proxy::unwrap(args.Holder());

	if (args.Length() < 1) {
		char errorStringBuffer[100];
		sprintf(errorStringBuffer, "createPaymentItem: Invalid number of arguments. Expected 1 but got %d", args.Length());
		return ThrowException(Exception::Error(String::New(errorStringBuffer)));
	}

	jvalue jArguments[1];




	bool isNew_0;
	
	if (!args[0]->IsNull()) {
		Local<Value> arg_0 = args[0];
		jArguments[0].l =
			titanium::TypeConverter::jsObjectToJavaKrollDict(env, arg_0, &isNew_0);
	} else {
		jArguments[0].l = NULL;
	}

	jobject javaProxy = proxy->getJavaObject();
	jobject jResult = (jobject)env->CallObjectMethodA(javaProxy, methodID, jArguments);



	if (!JavaObject::useGlobalRefs) {
		env->DeleteLocalRef(javaProxy);
	}



			if (isNew_0) {
				env->DeleteLocalRef(jArguments[0].l);
			}


	if (env->ExceptionCheck()) {
		Handle<Value> jsException = titanium::JSException::fromJavaException();
		env->ExceptionClear();
		return jsException;
	}

	if (jResult == NULL) {
		return Null();
	}

	Handle<Value> v8Result = titanium::TypeConverter::javaObjectToJsValue(env, jResult);

	env->DeleteLocalRef(jResult);


	return v8Result;

}

// Dynamic property accessors -------------------------------------------------


		} // paypal
		} // ti
