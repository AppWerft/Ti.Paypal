package de.appwerft.paypal;

import java.math.BigDecimal;

public class PaymentItem {
	String name;
	String sku, currency;
	int quantity;
	BigDecimal price;

	public PaymentItem() {
		this.name = "no name";
		this.sku = "no sku";
		this.quantity = 1;
		this.price = new BigDecimal(0);
		this.currency = "USD";
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	@Override
	public String toString() {
		return "quantity=" + quantity + " name=" + name + " sku=" + sku
				+ " currency" + currency + " price=" + price.toString();
	}

	public String getSku() {
		return sku;
	}

	public void setSku(String sku) {
		this.sku = sku;
	}

	public String getCurrency() {
		return currency;
	}

	public void setCurrency(String currency) {
		this.currency = currency;
	}

	public int getQuantity() {
		return quantity;
	}

	public void setQuantity(int quantity) {
		this.quantity = quantity;
	}

	public BigDecimal getPrice() {
		return price;
	}

	public void setPrice(BigDecimal price) {
		this.price = price;
	}

}