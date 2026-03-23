# 🏛️ Bytecoin Legacy ($BCNL) 

![Status](https://img.shields.io/badge/Network-Genesis_Phase-gold)
![Algorithm](https://img.shields.io/badge/PoW-CryptoNight_Legacy-blue)
![License](https://img.shields.io/badge/License-MIT-green)

**"El primer protocolo de privacidad, finalmente reclamado por quienes trabajan la red."**

Bytecoin Legacy ($BCNL) es el Hard Fork definitivo impulsado por la comunidad. Nace de la necesidad de limpiar el ecosistema original del 82% de suministro pre-minado atrapado en billeteras fantasmas desde 2012. 

En **Bytecoin Legacy**, el valor no le pertenece a fundadores desaparecidos; le pertenece a los mineros.

---

## 🔥 La Revolución Legacy

A diferencia del proyecto original abandonado, **BCNL** introduce cambios críticos en el consenso:

1. **Quema de Suministro Fantasma:** El código invalida cualquier output de billeteras sin movimiento desde marzo de 2018. El "supply" real es ahora propiedad de la comunidad activa.
2. **Justicia Proof of Work (PoW):** Algoritmo optimizado para CPU y GPU domésticas. No más dominancia de granjas de ASICs. Si tienes una PC, tienes una mina.
3. **Infraestructura 2026:** Código actualizado para ser compatible con CMake 3.20+, OpenSSL 3.0+ y compiladores modernos en Windows 11 y Linux.

## 🛠️ Especificaciones Técnicas

* **Ticker:** `$BCNL`
* **Algoritmo de Hash:** `CryptoNight-Legacy` (Dificultad adaptativa por bloque).
* **Tiempo de Bloque:** 120 segundos.
* **Emisión:** Recompensas de bloque reseteadas para incentivar a los nuevos mineros de la "Era Legacy".

---

## 🚀 Guía de Compilación Rápida (Build)

### Linux (Ubuntu 22.04 / 24.04+)
```bash
# Instalar dependencias modernas
sudo apt-get install build-essential cmake libboost-all-dev libssl-dev libudev-dev

# Clonar y compilar
git clone [https://github.com/bytecoiniva/Bytecoin-Legacy-PoW.git](https://github.com/bytecoiniva/Bytecoin-Legacy-PoW.git)
cd Bytecoin-Legacy-PoW
mkdir build && cd build
cmake ..
make -j$(nproc)

# Ejecutar el nodo
./bin/bytecoind --version
