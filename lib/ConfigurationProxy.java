package ti.paypal;

import org.appcelerator.kroll.KrollProxy;
import org.appcelerator.kroll.annotations.Kroll;

import ti.paypal.util.Configuration;

@Kroll.proxy(creatableInModule = PaypalModule.class)
public class ConfigurationProxy extends KrollProxy {
	private Configuration configuration;

	public ConfigurationProxy(Configuration c) {
		super();
		configuration = c;
	}

	public Configuration configuration() {
		return configuration;
	}

	public Configuration getConfiguration() {
		return configuration;
	}

}