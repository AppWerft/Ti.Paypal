package ti.paypal;

import org.appcelerator.kroll.KrollProxy;
import org.appcelerator.kroll.annotations.Kroll;
import ti.paypal.util.PaymentItem;

@Kroll.proxy(creatableInModule = PaypalModule.class)
public class PaymentItemProxy extends KrollProxy {
	private PaymentItem paymentItem;

	public PaymentItemProxy() {
		super();
	}

	public PaymentItem getPaymentItem() {
		return paymentItem;
	}
}