#!/bin/bash

APPID=ti.paypal
VERSION=3.0.6

#cp android/assets/* iphone/
cd android;ant clean; rm -rf build/*;ant ;  unzip -uo  dist/$APPID-android-$VERSION.zip  -d  ~/Library/Application\ Support/Titanium/;cd ..
#cd iphone/; python build.py;  unzip -uo  $APPID-iphone-$VERSION.zip  -d  ~/Library/Application\ Support/Titanium/;cd ..
cp android/dist/$APPID-android-$VERSION.zip .
#cp iphone/$APPID-iphone-$VERSION.zip .
