﻿// C++/WinRT v1.0.171013.2
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#include "winrt/impl/Windows.Security.Cryptography.Certificates.1.h"
#include "winrt/impl/Windows.Storage.Streams.1.h"
#include "winrt/impl/Windows.Security.Cryptography.Core.1.h"

WINRT_EXPORT namespace winrt::Windows::Security::Cryptography::Core {

}

namespace winrt::impl {

}

WINRT_EXPORT namespace winrt::Windows::Security::Cryptography::Core {

struct AsymmetricAlgorithmNames
{
    AsymmetricAlgorithmNames() = delete;
    static hstring RsaPkcs1();
    static hstring RsaOaepSha1();
    static hstring RsaOaepSha256();
    static hstring RsaOaepSha384();
    static hstring RsaOaepSha512();
    static hstring EcdsaP256Sha256();
    static hstring EcdsaP384Sha384();
    static hstring EcdsaP521Sha512();
    static hstring DsaSha1();
    static hstring DsaSha256();
    static hstring RsaSignPkcs1Sha1();
    static hstring RsaSignPkcs1Sha256();
    static hstring RsaSignPkcs1Sha384();
    static hstring RsaSignPkcs1Sha512();
    static hstring RsaSignPssSha1();
    static hstring RsaSignPssSha256();
    static hstring RsaSignPssSha384();
    static hstring RsaSignPssSha512();
    static hstring EcdsaSha256();
    static hstring EcdsaSha384();
    static hstring EcdsaSha512();
};

struct WINRT_EBO AsymmetricKeyAlgorithmProvider :
    Windows::Security::Cryptography::Core::IAsymmetricKeyAlgorithmProvider,
    impl::require<AsymmetricKeyAlgorithmProvider, Windows::Security::Cryptography::Core::IAsymmetricKeyAlgorithmProvider2>
{
    AsymmetricKeyAlgorithmProvider(std::nullptr_t) noexcept {}
    static Windows::Security::Cryptography::Core::AsymmetricKeyAlgorithmProvider OpenAlgorithm(param::hstring const& algorithm);
};

struct CryptographicEngine
{
    CryptographicEngine() = delete;
    static Windows::Storage::Streams::IBuffer Encrypt(Windows::Security::Cryptography::Core::CryptographicKey const& key, Windows::Storage::Streams::IBuffer const& data, Windows::Storage::Streams::IBuffer const& iv);
    static Windows::Storage::Streams::IBuffer Decrypt(Windows::Security::Cryptography::Core::CryptographicKey const& key, Windows::Storage::Streams::IBuffer const& data, Windows::Storage::Streams::IBuffer const& iv);
    static Windows::Security::Cryptography::Core::EncryptedAndAuthenticatedData EncryptAndAuthenticate(Windows::Security::Cryptography::Core::CryptographicKey const& key, Windows::Storage::Streams::IBuffer const& data, Windows::Storage::Streams::IBuffer const& nonce, Windows::Storage::Streams::IBuffer const& authenticatedData);
    static Windows::Storage::Streams::IBuffer DecryptAndAuthenticate(Windows::Security::Cryptography::Core::CryptographicKey const& key, Windows::Storage::Streams::IBuffer const& data, Windows::Storage::Streams::IBuffer const& nonce, Windows::Storage::Streams::IBuffer const& authenticationTag, Windows::Storage::Streams::IBuffer const& authenticatedData);
    static Windows::Storage::Streams::IBuffer Sign(Windows::Security::Cryptography::Core::CryptographicKey const& key, Windows::Storage::Streams::IBuffer const& data);
    static bool VerifySignature(Windows::Security::Cryptography::Core::CryptographicKey const& key, Windows::Storage::Streams::IBuffer const& data, Windows::Storage::Streams::IBuffer const& signature);
    static Windows::Storage::Streams::IBuffer DeriveKeyMaterial(Windows::Security::Cryptography::Core::CryptographicKey const& key, Windows::Security::Cryptography::Core::KeyDerivationParameters const& parameters, uint32_t desiredKeySize);
    static Windows::Storage::Streams::IBuffer SignHashedData(Windows::Security::Cryptography::Core::CryptographicKey const& key, Windows::Storage::Streams::IBuffer const& data);
    static bool VerifySignatureWithHashInput(Windows::Security::Cryptography::Core::CryptographicKey const& key, Windows::Storage::Streams::IBuffer const& data, Windows::Storage::Streams::IBuffer const& signature);
    static Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer> DecryptAsync(Windows::Security::Cryptography::Core::CryptographicKey const& key, Windows::Storage::Streams::IBuffer const& data, Windows::Storage::Streams::IBuffer const& iv);
    static Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer> SignAsync(Windows::Security::Cryptography::Core::CryptographicKey const& key, Windows::Storage::Streams::IBuffer const& data);
    static Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer> SignHashedDataAsync(Windows::Security::Cryptography::Core::CryptographicKey const& key, Windows::Storage::Streams::IBuffer const& data);
};

struct WINRT_EBO CryptographicHash :
    Windows::Security::Cryptography::Core::IHashComputation
{
    CryptographicHash(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CryptographicKey :
    Windows::Security::Cryptography::Core::ICryptographicKey
{
    CryptographicKey(std::nullptr_t) noexcept {}
};

struct EccCurveNames
{
    EccCurveNames() = delete;
    static hstring BrainpoolP160r1();
    static hstring BrainpoolP160t1();
    static hstring BrainpoolP192r1();
    static hstring BrainpoolP192t1();
    static hstring BrainpoolP224r1();
    static hstring BrainpoolP224t1();
    static hstring BrainpoolP256r1();
    static hstring BrainpoolP256t1();
    static hstring BrainpoolP320r1();
    static hstring BrainpoolP320t1();
    static hstring BrainpoolP384r1();
    static hstring BrainpoolP384t1();
    static hstring BrainpoolP512r1();
    static hstring BrainpoolP512t1();
    static hstring Curve25519();
    static hstring Ec192wapi();
    static hstring NistP192();
    static hstring NistP224();
    static hstring NistP256();
    static hstring NistP384();
    static hstring NistP521();
    static hstring NumsP256t1();
    static hstring NumsP384t1();
    static hstring NumsP512t1();
    static hstring SecP160k1();
    static hstring SecP160r1();
    static hstring SecP160r2();
    static hstring SecP192k1();
    static hstring SecP192r1();
    static hstring SecP224k1();
    static hstring SecP224r1();
    static hstring SecP256k1();
    static hstring SecP256r1();
    static hstring SecP384r1();
    static hstring SecP521r1();
    static hstring Wtls7();
    static hstring Wtls9();
    static hstring Wtls12();
    static hstring X962P192v1();
    static hstring X962P192v2();
    static hstring X962P192v3();
    static hstring X962P239v1();
    static hstring X962P239v2();
    static hstring X962P239v3();
    static hstring X962P256v1();
    static Windows::Foundation::Collections::IVectorView<hstring> AllEccCurveNames();
};

struct WINRT_EBO EncryptedAndAuthenticatedData :
    Windows::Security::Cryptography::Core::IEncryptedAndAuthenticatedData
{
    EncryptedAndAuthenticatedData(std::nullptr_t) noexcept {}
};

struct HashAlgorithmNames
{
    HashAlgorithmNames() = delete;
    static hstring Md5();
    static hstring Sha1();
    static hstring Sha256();
    static hstring Sha384();
    static hstring Sha512();
};

struct WINRT_EBO HashAlgorithmProvider :
    Windows::Security::Cryptography::Core::IHashAlgorithmProvider
{
    HashAlgorithmProvider(std::nullptr_t) noexcept {}
    static Windows::Security::Cryptography::Core::HashAlgorithmProvider OpenAlgorithm(param::hstring const& algorithm);
};

struct KeyDerivationAlgorithmNames
{
    KeyDerivationAlgorithmNames() = delete;
    static hstring Pbkdf2Md5();
    static hstring Pbkdf2Sha1();
    static hstring Pbkdf2Sha256();
    static hstring Pbkdf2Sha384();
    static hstring Pbkdf2Sha512();
    static hstring Sp800108CtrHmacMd5();
    static hstring Sp800108CtrHmacSha1();
    static hstring Sp800108CtrHmacSha256();
    static hstring Sp800108CtrHmacSha384();
    static hstring Sp800108CtrHmacSha512();
    static hstring Sp80056aConcatMd5();
    static hstring Sp80056aConcatSha1();
    static hstring Sp80056aConcatSha256();
    static hstring Sp80056aConcatSha384();
    static hstring Sp80056aConcatSha512();
    static hstring CapiKdfMd5();
    static hstring CapiKdfSha1();
    static hstring CapiKdfSha256();
    static hstring CapiKdfSha384();
    static hstring CapiKdfSha512();
};

struct WINRT_EBO KeyDerivationAlgorithmProvider :
    Windows::Security::Cryptography::Core::IKeyDerivationAlgorithmProvider
{
    KeyDerivationAlgorithmProvider(std::nullptr_t) noexcept {}
    static Windows::Security::Cryptography::Core::KeyDerivationAlgorithmProvider OpenAlgorithm(param::hstring const& algorithm);
};

struct WINRT_EBO KeyDerivationParameters :
    Windows::Security::Cryptography::Core::IKeyDerivationParameters,
    impl::require<KeyDerivationParameters, Windows::Security::Cryptography::Core::IKeyDerivationParameters2>
{
    KeyDerivationParameters(std::nullptr_t) noexcept {}
    static Windows::Security::Cryptography::Core::KeyDerivationParameters BuildForPbkdf2(Windows::Storage::Streams::IBuffer const& pbkdf2Salt, uint32_t iterationCount);
    static Windows::Security::Cryptography::Core::KeyDerivationParameters BuildForSP800108(Windows::Storage::Streams::IBuffer const& label, Windows::Storage::Streams::IBuffer const& context);
    static Windows::Security::Cryptography::Core::KeyDerivationParameters BuildForSP80056a(Windows::Storage::Streams::IBuffer const& algorithmId, Windows::Storage::Streams::IBuffer const& partyUInfo, Windows::Storage::Streams::IBuffer const& partyVInfo, Windows::Storage::Streams::IBuffer const& suppPubInfo, Windows::Storage::Streams::IBuffer const& suppPrivInfo);
    static Windows::Security::Cryptography::Core::KeyDerivationParameters BuildForCapi1Kdf(Windows::Security::Cryptography::Core::Capi1KdfTargetAlgorithm const& capi1KdfTargetAlgorithm);
};

struct MacAlgorithmNames
{
    MacAlgorithmNames() = delete;
    static hstring HmacMd5();
    static hstring HmacSha1();
    static hstring HmacSha256();
    static hstring HmacSha384();
    static hstring HmacSha512();
    static hstring AesCmac();
};

struct WINRT_EBO MacAlgorithmProvider :
    Windows::Security::Cryptography::Core::IMacAlgorithmProvider,
    impl::require<MacAlgorithmProvider, Windows::Security::Cryptography::Core::IMacAlgorithmProvider2>
{
    MacAlgorithmProvider(std::nullptr_t) noexcept {}
    static Windows::Security::Cryptography::Core::MacAlgorithmProvider OpenAlgorithm(param::hstring const& algorithm);
};

struct PersistedKeyProvider
{
    PersistedKeyProvider() = delete;
    static Windows::Foundation::IAsyncOperation<Windows::Security::Cryptography::Core::CryptographicKey> OpenKeyPairFromCertificateAsync(Windows::Security::Cryptography::Certificates::Certificate const& certificate, param::hstring const& hashAlgorithmName, Windows::Security::Cryptography::Core::CryptographicPadding const& padding);
    static Windows::Security::Cryptography::Core::CryptographicKey OpenPublicKeyFromCertificate(Windows::Security::Cryptography::Certificates::Certificate const& certificate, param::hstring const& hashAlgorithmName, Windows::Security::Cryptography::Core::CryptographicPadding const& padding);
};

struct SymmetricAlgorithmNames
{
    SymmetricAlgorithmNames() = delete;
    static hstring DesCbc();
    static hstring DesEcb();
    static hstring TripleDesCbc();
    static hstring TripleDesEcb();
    static hstring Rc2Cbc();
    static hstring Rc2Ecb();
    static hstring AesCbc();
    static hstring AesEcb();
    static hstring AesGcm();
    static hstring AesCcm();
    static hstring AesCbcPkcs7();
    static hstring AesEcbPkcs7();
    static hstring DesCbcPkcs7();
    static hstring DesEcbPkcs7();
    static hstring TripleDesCbcPkcs7();
    static hstring TripleDesEcbPkcs7();
    static hstring Rc2CbcPkcs7();
    static hstring Rc2EcbPkcs7();
    static hstring Rc4();
};

struct WINRT_EBO SymmetricKeyAlgorithmProvider :
    Windows::Security::Cryptography::Core::ISymmetricKeyAlgorithmProvider
{
    SymmetricKeyAlgorithmProvider(std::nullptr_t) noexcept {}
    static Windows::Security::Cryptography::Core::SymmetricKeyAlgorithmProvider OpenAlgorithm(param::hstring const& algorithm);
};

}
