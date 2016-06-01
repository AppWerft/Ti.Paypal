package ti.paypal.util;

import org.appcelerator.kroll.KrollDict;

import org.appcelerator.titanium.util.TiConvert;

import java.math.BigDecimal;

/**
 * Represents an in-app billing purchase.
 */
public class PaymentItem {
	String name = "", sku = "", currency = "EU";
	BigDecimal price = new BigDecimal(0);
	int quantify = 1;

	public PaymentItem(KrollDict args) {
		if (args.containsKeyAndNotNull("name")) {
			name = TiConvert.toString(args.get("name"));
		}
		if (args.containsKeyAndNotNull("price")) {
			price = new BigDecimal(TiConvert.toString(args.get("price")));
		}
		if (args.containsKeyAndNotNull("sku")) {
			sku = TiConvert.toString(args.get("sku"));
		}
		if (args.containsKeyAndNotNull("quantify")) {
			quantify = TiConvert.toInt(args.get("quantify"));
		}
		if (args.containsKeyAndNotNull("currency")) {
			currency = TiConvert.toString(args.get("currency"));
		}
	}

	@Override
	public String toString() {
		return "PaymentItem(name:" + name + ", price:" + price + ", sku:" + sku
				+ ", quantify:" + quantify + ", currency:" + currency + ")";
	}
}