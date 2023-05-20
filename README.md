# CdC_spectrum

Ceci est ma participation au premier Codeathon dans le cadre du forum CdC.
Le projet n'est pas compatibles pour les systèmes windows mais il ne devrai pas être difficile à porter
Seulement les fichiers WAV sont supporté, il faudra donc les encoder avec FFMPEG si besoin.

# Dépendances externes
-SDL2

# Build le projet

```
git clone --recursive https://github.com/Warez-L/CdC_spectrum.git
cd CdC_spectrum/
cmake -S . -B build
cd build/
make -j8
./src/LV_Spectrum <Your WAV File>
```
