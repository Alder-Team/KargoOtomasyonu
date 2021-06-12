#ifndef TEMEL_VERI_YONETICISI_H
#define TEMEL_VERI_YONETICISI_H


#include <QObject>
#include <Veri/tanimlar.h>
#include <Veri/VeriListesi/krgalicibilgileri.h>
#include <Veri/VeriListesi/krggondericibilgileri.h>
#include <Veri/VeriListesi/krgkargobilgileri.h>
#include <Veri/VeriListesi/krgsubebilgileri.h>


template <class V, class P>

class TemelVeriYonetici {
public:
    typedef V Veri;
    typedef P Ptr;
    typedef QList<Ptr> VeriListesi;
    typedef std::function<bool(Ptr)> Sart;

    explicit TemelVeriYonetici() { enSonId = 0; }


    // 1-yeni kargo oluşturur

    Ptr yeni() const{
        Ptr yeni = std::make_shared<Veri>();
        return yeni;
    }

    // 2-yeni kargoyu listeye ekler

    void ekle(Ptr kargo){
        kargo->setId(enSonId++);
        veriler.append(kargo);
    }

    // 3-kargoyu listeden siler

    Ptr sil(IdTuru kargoId){
        for (int i=0; i<veriler.size(); i++) {
            if (veriler[i]->getId() == kargoId) {
                Ptr sonuc = veriler.takeAt(i);
                return sonuc;
            }
        }
        throw QObject::tr("Aranılan kargo bulunamadı! Silme işlemi iptal edildi");
    }
    Ptr sil(Ptr kargo){ return sil(kargo->getId()); }

    // 5-kargo arama

    Ptr ilkiniBul(Sart f){
        for (int i=0; i<veriler.size(); i++) {
            auto veri_i = veriler[i];
            if (f(veri_i)) {
                return veri_i;
            }
        }
        throw QObject::tr("Aranılan veri bulunamadı.");
    }
    Ptr sonuncuyuBul(Sart f){
        for (int i=veriler.size() - 1; i>=0; i--) {
            auto veri_i = veriler[i];
            if (f(veri_i)) {
                return veri_i;
            }
        }
        throw QObject::tr("Aranılan veri bulunamadı.");
    }
    VeriListesi tumunuBul(Sart f){
        VeriListesi sonuc;

        for (int i=0; i<veriler.size(); i++) {
            Ptr veri_i = veriler[i];
            if (f(veri_i)) {
                sonuc.append(veri_i);
            }
        }
        return sonuc;
    }


protected:
    VeriListesi veriler;
    IdTuru enSonId;

    template<class a1, class b1>
    friend QDataStream &operator<<(QDataStream &stream, TemelVeriYonetici<a1, b1> &veri);

    template<class a2, class b2>
    friend QDataStream &operator>>(QDataStream &stream, TemelVeriYonetici<a2, b2> &veri);



};

template<class V, class P>
QDataStream &operator<<(QDataStream &stream, TemelVeriYonetici<V, P> &veri)
{
    stream << veri.enSonId << veri.veriler;
    return stream;
}

template<class V, class P>
QDataStream &operator>>(QDataStream &stream, TemelVeriYonetici<V, P> &veri)
{
    stream >> veri.enSonId >> veri.veriler;
    return stream;
}

#endif // TEMEL_VERI_YONETICISI_H
