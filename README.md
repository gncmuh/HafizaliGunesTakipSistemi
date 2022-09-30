# HafizaliGunesTakipSistemi
# HAFIZALI AKILLI GÜNEŞ TAKİP SİSTEMİ

Merhabalar bu projemi de sizlerle paylaşmaktan büyük bir mutluluk duyuyorum projeye gelecek olursak akıllı güneş panellerinin çalışmasına benzer fakat güneş konumlarının zamansal olarak tarayan ve hafızaya aldıktan sonra güneş konumuna gelen bir sistemdir.



Bu projede güneş paneli üzerine yerleştirilmiş olan bir adet ldr bulunmaktadır. Sistem 35 saniye de bir servo motor 0 dereceden başlayarak 180 dereceye kadar tarama yapar ve bunları bir hafıza dizisi içerisinde depolar. Dizinin içerisine ldr’nin ortamdan algıladığı veriler kaydedilir.


				
Her bir servo açısı sistem hafızasında bir dizi sırasını ifade etmektedir. Yukarıda ki resimde bu durum açıklanmıştır. Ldr üzerine düşen yoğun güneş ışığı ldr üzerinde minimum değer ifade etmektedir. Güneşin yani ışık kaynağının üzerine bir yerde olduğu tahmin edilir ve hafıza üzerine yazılan ldr değerinin karşılığına sahip olan açı değeri (dizi sırası)  güneş konum açısını vermektedir. Bu açı değeri servo üzerinde kullanılarak güneşin konumuna gelmesi sağlanmaktadır. 

