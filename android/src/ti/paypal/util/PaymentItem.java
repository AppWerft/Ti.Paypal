package ti.paypal.util;

import org.appcelerator.kroll.KrollDict;

import java.math.BigDecimal;

/**
 * Represents an PaymentItem.
 */
@SuppressWarnings("serial")
public class PaymentItem extends KrollDict {
	String name = "", sku = "", currency = "EU";
	BigDecimal price = new BigDecimal(0);
	int quantify = 1;

	public PaymentItem() {
		super();
		name = "";
		sku = "";
		currency = "EU";
		price = new BigDecimal(0);
	    quantify = 1;
	}

	@Override
	public String toString() {
		return "PaymentItem(name:" + name + ", price:" + price + ", sku:" + sku
				+ ", quantify:" + quantify + ", currency:" + currency + ")";
	}
}