package ti.paypal; 
 
import org.appcelerator.kroll.KrollProxy; 
import org.appcelerator.kroll.annotations.Kroll; 
 
import ti.paypal.util.PaymentItem; 
 
@Kroll.proxy 
public class PaymentItemProxy extends KrollProxy { 
    private PaymentItem paymentItem; 
    public PaymentItemProxy(PaymentItem p) { 
        super(); 
        paymentItem = p; 
    } 
    
	@Kroll.method
	public PaymentItem createPaymentItem() {
		return paymentItem;
	}

    public PaymentItem getPaymentItem() { return paymentItem; } 
}