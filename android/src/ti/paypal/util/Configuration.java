package ti.paypal.util;

import org.appcelerator.kroll.KrollDict;
import org.appcelerator.titanium.util.TiConvert;

/**
 * Represents a configuration.
 */
public class Configuration {
	String merchantName, merchantPrivacyPolicyURL = "http://google.com",
			merchantUserAgreementURL = "http://google.com", locale = "en";

	public Configuration(KrollDict args) {
		if (args.containsKeyAndNotNull("merchantName")) {
			merchantName = TiConvert.toString(args.get("merchantName"));
		}
		if (args.containsKeyAndNotNull("merchantPrivacyPolicyURL")) {
			merchantPrivacyPolicyURL = TiConvert.toString(args
					.get("merchantPrivacyPolicyURL"));
		}
		if (args.containsKeyAndNotNull("merchantUserAgreementURL")) {
			merchantUserAgreementURL = TiConvert.toString(args
					.get("merchantUserAgreementURL"));
		}
	}

	@Override
	public String toString() {
		return "Configuration(merchantName:" + merchantName + ")";
	}

}