package ti.paypal;

import java.math.BigDecimal;

import org.appcelerator.kroll.KrollDict;
import org.appcelerator.kroll.KrollProxy;
import org.appcelerator.kroll.annotations.Kroll;
import org.appcelerator.titanium.util.TiConvert;

import ti.paypal.util.PaymentItem;

@Kroll.proxy(creatableInModule = PaypalModule.class)
public class PaymentItemProxy extends KrollProxy {
	private PaymentItem paymentItem;
	private String name = "", sku = "", currency = "EU";
	private BigDecimal price = new BigDecimal(0);
	int quantify = 1;
	public PaymentItemProxy() {
		super();
	}

	public PaymentItem getPaymentItem() {
		return paymentItem;
	}
	
	// Handle creation options
	@Override
	public void handleCreationDict(KrollDict args) {
		if (args.containsKeyAndNotNull("name")) {
			this.name = TiConvert.toString(args.get("name"));
		}
		if (args.containsKeyAndNotNull("price")) {
			this.price = new BigDecimal(TiConvert.toString(args.get("price")));
		}
		if (args.containsKeyAndNotNull("sku")) {
			this.sku = TiConvert.toString(args.get("sku"));
		}
		if (args.containsKeyAndNotNull("quantify")) {
			this.quantify = TiConvert.toInt(args.get("quantify"));
		}
		if (args.containsKeyAndNotNull("currency")) {
			this.currency = TiConvert.toString(args.get("currency"));
		}
		
	}
	
}