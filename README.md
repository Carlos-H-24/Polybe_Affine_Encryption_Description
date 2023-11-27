# Polybe_Affine_Encryption_Description

## Projet de Chiffrement et Déchiffrement avec Qt C++

Ce projet utilise Qt C++ pour implémenter les algorithmes de chiffrement affine et de chiffrement/dechiffrement Polybe. Ces algorithmes sont couramment utilisés pour la sécurité basique des données.

## Contenu des Fichiers

- **main.cpp:** Le fichier principal qui crée l'application Qt.
- **encryption.cpp:** Implémente la classe `Encryption` qui contient les fonctionnalités de chiffrement et déchiffrement.
- **encryption.hpp:** Le fichier d'en-tête de la classe `Encryption`.
- **form.ui:** Le fichier de conception de l'interface utilisateur.

## Utilisation

### Chiffrement et Déchiffrement Polybe

La classe `Encryption` offre les méthodes suivantes pour le chiffrement/dechiffrement Polybe :
- `createSubstitutionGrid`: Crée une grille de substitution en utilisant un mot-clé.
- `polybiusEncrypt`: Chiffre un message en utilisant la grille Polybe.
- `polybiusDecrypt`: Déchiffre un message Polybe.

### Chiffrement et Déchiffrement Affine

La classe `Encryption` propose également des méthodes pour le chiffrement et le déchiffrement affine :
- `encryptAffine`: Chiffre un texte clair en utilisant la méthode affine.
- `decryptAffine`: Déchiffre un texte chiffré avec la méthode affine.

## Utilisation de l'Application

1. **Polybe:**
   - Saisissez un mot-clé dans le champ prévu.
   - Sélectionnez le type d'opération (chiffrement ou déchiffrement).
   - Saisissez le message dans la zone de texte.
   - Cliquez sur le bouton correspondant.

2. **Affine:**
   - Saisissez les coefficients \(a\) et \(b\) dans les champs prévus.
   - Sélectionnez le type d'opération (chiffrement ou déchiffrement).
   - Saisissez le message dans la zone de texte.
   - Cliquez sur le bouton correspondant.

## Remarques

- Veillez à respecter les prérequis (Qt C++) pour compiler et exécuter le projet.
- Ce projet est à des fins éducatives et peut ne pas être adapté à des applications de sécurité réelles.

## Auteur

AKODJENOU Hervé Carlos

---
