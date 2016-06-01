package ti.paypal;

import org.appcelerator.kroll.KrollDict;
import org.appcelerator.kroll.KrollProxy;
import org.appcelerator.kroll.annotations.Kroll;
import org.appcelerator.titanium.util.TiConvert;
import ti.paypal.util.PaymentItem;
import java.math.BigDecimal;

@Kroll.proxy(creatableInModule = PaypalModule.class)
public class PaymentItemProxy extends KrollProxy {
	public PaymentItem item;
	public PaymentItemProxy() {
		super();
	}

	public PaymentItem getPaymentItem() {
		return item;
	}

	// Handle creation options
	@Override
	public void handleCreationDict(KrollDict args) {
		item = new PaymentItem();
		if (args.containsKeyAndNotNull("name")) {
			item.put("name", TiConvert.toString(args.get("name")));
		}
		if (args.containsKeyAndNotNull("price")) {
			item.put("price",
					new BigDecimal(TiConvert.toString(args.get("price"))));
		}
		if (args.containsKeyAndNotNull("sku")) {
			item.put("sku", TiConvert.toString(args.get("sku")));
		}
		if (args.containsKeyAndNotNull("quantify")) {
			item.put("quantify", TiConvert.toInt(args.get("quantify")));
		}
		if (args.containsKeyAndNotNull("currency")) {
			item.put("currency", TiConvert.toString(args.get("currency")));
		}
	}
}