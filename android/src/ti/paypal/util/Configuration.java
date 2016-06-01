package ti.paypal.util;

import org.appcelerator.kroll.KrollDict;


/**
 * Represents a configuration.
 */
@SuppressWarnings("serial")
public class Configuration extends KrollDict{
	String merchantName, merchantPrivacyPolicyURL = "http://google.com",
			merchantUserAgreementURL = "http://google.com", locale = "en";

	public Configuration() {
	}

	@Override
	public String toString() {
		return "Configuration(merchantName:" + merchantName + ")";
	}

}