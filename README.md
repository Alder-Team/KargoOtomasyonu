# Kargo Firma Otomasyonu

![](doc/doc-images/img-0001-girisekrani.png)

Hızlı erişim:
- [Detaylar](#Detaylar)
    - [Projenin Kapsamı](#Projenin-Kapsamı)
    - [Yapalıcaklar Listemiz](#Yapılacaklar-Listemiz)
        - Check-List
    - [Şube Ekleme](#Şube-Ekleme)
    - [Kargo Ekleme](#Kargo-Ekleme)
-


---

## Detaylar

### Projenin Kapsamı
Karadeniz Teknik Üniversitesi İstatistik ve Bilgisayar Bilimleri 2. Sınıf ikinci dönem Nesne Yönelimli Programlama dersi vize projesi.

2021 yılı 2. sınıf Bahar Dönemi N.Y.P. dersinde hocamız **Tolga Berber** C++ dilini ve Qt kütüphanesinin araçlarını kullanarak yapabileceğimiz 3 adet proje belirledi.

- **Belediye Taşımacılığı Yönetimi**: Bu yazılımda bir belediyeye ait toplu taşıma sisteminin yönetilmesi istenmektedir.

- **Teknoloji Marketi Otomasyonu**: Bu projede, bir teknoloji marketine ait ürünlerin yönetilmesi istenmektedir.

- **Kargo Firma Otomasyonu**: Bir kargo firmasına ait gönderilerin yönetimini sağlayan bir yazılım
geliştirmemiz beklenmektedir.

Bu projelerden bir tanesini en az 2 kişi, en fazla 3 kişilik gruplar halinde yapılmasını zorunlu tuttu. Biz 3 arkadaş olarak Kargo firma otomasyonu projesini yapmaya karar verdik.

### Yapılacaklar Listemiz

**Hedef**

Yazılımın aşağıdaki yetenekleri sağlamalıdır!

1. Gönderiler sisteme kaydedilebilmelidir.

    - Her gönderinin desi türünden hesabı yapılabilmelidir Gönderi fiyatı desi üzerinden yapılacaktır.

        - Desi hesabı ağırlık veya hacim ile hesaplanabilir

            - Normalde sadece hacim ile hesaplanır fakat firma ağırlık ile hesaplama mekanizması da istemektedir.

    - Gönderilerin ödemesine göre 2 farklı tür olabilir!

        - Gönderici Ödemeli

        - Alıcı Ödemeli

2. Firma Hizmet verdiği illeri (şubelerini) ve aralarındaki mesafeleri yazılıma girebilmelidir.

3. Firma gönderdiği adresleri kaydetmek istemektedir. Bu sebeple, gönderici veya alıcı adına göre gönderi esnasında kayıt yapılabilmelidir.

**Bonus**: Gönderilerin geliş sıralarına göre gönderilmeleri. (Yukarıdaki adımlar tamamlandıktan sonra değerlendirmeye
tabidir.)

#### Check-List

- [x] Gönderiler sisteme kaydedilebilmelidir.

- [x] Her gönderinin desi türünden hesabı yapılabilmelidir Gönderi fiyatı desi üzerinden yapılacaktır.

- [x] Desi hesabı hacim üzerinden yapılabiliyor.

- [ ] Normalde sadece hacim ile hesaplanır fakat firma ağırlık ile hesaplama mekanizması da istemektedir.

- [x] Gönderilerin ödemesine göre 2 farklı tür olabilir! (Alici Ödemeli , Gönderici Ödemeli)

- [x] Firma Hizmet verdiği illeri (şubelerini girebilmelidir.

- [x] Firma Hizmet verdiği illerin mesafelerini yazılıma girebilmelidir. **Karayolları Genel Müdürlüğündeki iller arasındaki mesafe veritabanı kullanıldı.** 

- [x] Firma gönderdiği adresleri kaydetmek istemektedir. Bu sebeple, gönderici veya alıcı adına göre gönderi esnasında kayıt yapılabilmelidir.

### Bilinen Sorunlar

**Kritik:**
- Program ilk çalıştığında eğer şube eklenmediyse Kargo ekle ekranı çöküyor. 
- Bazen anlamsız şekilde çöküyor.

**Normal**
- Kargo Ekle ekranındaki sinyal slot bağlantısı olan Label'lar ilk açıldığında rastgele sayılar üretiyor. 

### Şube Ekleme

![](doc/doc-images/img-0002-subeekleekrani.png)

Tutarın hesaplanması için ilk olarak şubelerin eklenmesi gerektir. Kargo tutarların hesaplanması oluşturduğumuz tablo için [tıklayın]().

Bu ekran da şube adı, telefon numarası, yetkiki kişi ve şube ekranını kaydediyoruz. 

Bu ekranda KGM'den çektiğimiz iller arası uzaklık tablosunu kullanmak için Şube illerini önceden tanımladık. Tutarı hesaplamak ilin seçilmesi gerekmektedir.


### Kargo Ekleme

![](doc/doc-images/img-0003-kargoekleekrani.png)

Şubenin yeni kargo kaydetmesini sağlar. Bu ekranda Desi Hesaplama, Şube seçimi ve müşteri detayları bulanmaktadır. Bu bilgileri sisteme kaydetmektedir.





### Kargo Tutarlarların Hesaplanması

Elimizde 24x30x26 ebatlarında bir kolimiz olduğunu düşünelim. Kargo tutarını hesaplamak için önce desiyi hesaplamamız gereklidir. 

`Desi = En x Boy x Yükseklik / 3000`

formülünden  yararlanarak desi hesaplanır. Örneğimizdeki kolinin desisi 6.24 gelmekte. 

Kargoları ücretlendirmek için yolların mesafelerini bölge


https://www.kgm.gov.tr/Sayfalar/KGM/SiteTr/Root/Uzakliklar.aspx

Çorum - İstanbul 614

Adıyaman - Gaziantep 150 km

Trabzon - İstanbul 1248 km

---


## Yazılımı geliştirirken kullandığımız araçlar ve diller

- C++

- Qt

- Git

---
  
## Yazılımı geliştiren kişiler

- Gülnur Ögür / [GitHub](https://github.com/gulnurogur "Gülnur Ögür Github Profili"), [Linkedin]()
- Hüseyin Mutlu / [GitHub](https://github.com/huseyin5 "Hüseyin Mutlu Github Profili"), [Linkedin]()
- Ali Eren Ekinci /[GitHub](https://github.com/alierenekinci "Ali Eren Ekinci Github Profili"), [Linkedin]()


## Teşekkürler
- Dr.Öğr.Üyesi TOLGA BERBER - Karadeniz Teknik Üniversitesi Fen Fakültesi İstatistik ve Bilgisayar Bilimleri Bölümü /[Avesis](https://avesis.ktu.edu.tr/tberber), [Linkedin](https://www.linkedin.com/in/tolga-berber-606b2218/)
- Ozan Hanedan / [GitHub](https://github.com/ohanedan), [Linkedin](https://www.linkedin.com/in/ozanhanedan/)

