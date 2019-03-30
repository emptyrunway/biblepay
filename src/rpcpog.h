// Copyright (c) 2014-2019 The Dash Core Developers, The BiblePay Developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef RPCPOG_H
#define RPCPOG_H

#include "wallet/wallet.h"
#include "hash.h"
#include "net.h"
#include "utilstrencodings.h"
#include <univalue.h>

class CWallet;


std::string RetrieveMd5(std::string s1);

struct UserVote
{
	int nTotalYesCount = 0;
	int nTotalNoCount = 0;
	int nTotalAbstainCount = 0;
	int nTotalYesWeight = 0;
	int nTotalNoWeight = 0;
	int nTotalAbstainWeight = 0;
};

struct CPK
{
  std::string sAddress;
  int64_t nLockTime = 0;
  std::string sCampaign;
  std::string sNickName;
  std::string sError;
  double nProminence = 0;
  double nPoints = 0;
  bool fValid = false;
};

CAmount CAmountFromValue(const UniValue& value);
std::string RoundToString(double d, int place);
std::string QueryBibleHashVerses(uint256 hash, uint64_t nBlockTime, uint64_t nPrevBlockTime, int nPrevHeight, CBlockIndex* pindexPrev);
CAmount GetDailyMinerEmissions(int nHeight);
std::string CreateBankrollDenominations(double nQuantity, CAmount denominationAmount, std::string& sError);
std::string DefaultRecAddress(std::string sType);
std::string GenerateNewAddress(std::string& sError, std::string sName);
CAmount SelectCoinsForTithing(const CBlockIndex* pindex);
CAmount GetTitheTotal(CTransaction tx);
bool IsTitheLegal(CTransaction ctx, CBlockIndex* pindex, CAmount tithe_amount);
void GetTxTimeAndAmountAndHeight(uint256 hashInput, int hashInputOrdinal, int64_t& out_nTime, CAmount& out_caAmount, int& out_height);
std::string SendTithe(CAmount caTitheAmount, double dMinCoinAge, CAmount caMinCoinAmount, CAmount caMaxTitheAmount,
	std::string sSpecificTxId, int nSpecificOutput, std::string& sError);
CAmount GetTitheCap(const CBlockIndex* pindexLast);
double R2X(double var);
double Quantize(double nFloor, double nCeiling, double nValue);
CAmount Get24HourTithes(const CBlockIndex* pindexLast);
double GetPOGDifficulty(const CBlockIndex* pindex);
std::string GetActiveProposals();
bool VoteManyForGobject(std::string govobj, std::string strVoteSignal, std::string strVoteOutcome, 
	int iVotingLimit, int& nSuccessful, int& nFailed, std::string& sError);
bool AmIMasternode();
std::string CreateGovernanceCollateral(uint256 GovObjHash, CAmount caFee, std::string& sError);
int GetNextSuperblock();
std::string StoreBusinessObjectWithPK(UniValue& oBusinessObject, std::string& sError);
std::string StoreBusinessObject(UniValue& oBusinessObject, std::string& sError);
bool is_email_valid(const std::string& e);
UniValue GetBusinessObjectList(std::string sType);
UniValue GetBusinessObjectByFieldValue(std::string sType, std::string sFieldName, std::string sSearchValue);
double GetBusinessObjectTotal(std::string sType, std::string sFieldName, int iAggregationType);
std::string GetBusinessObjectList(std::string sType, std::string sFields);
UniValue GetBusinessObject(std::string sType, std::string sPrimaryKey, std::string& sError);
double GetSporkDouble(std::string sName, double nDefault);
int64_t GetFileSize(std::string sPath);
std::string AddBlockchainMessages(std::string sAddress, std::string sType, std::string sPrimaryKey, 
	std::string sHTML, CAmount nAmount, double minCoinAge, std::string& sError);
std::string ReadCache(std::string sSection, std::string sKey);
void ClearCache(std::string sSection);
std::string ReadCacheWithMaxAge(std::string sSection, std::string sKey, int64_t nMaxAge);
void WriteCache(std::string sSection, std::string sKey, std::string sValue, int64_t locktime, bool IgnoreCase=true);
void PurgeCacheAsOfExpiration(std::string sSection, int64_t nExpiration);
std::string GetSporkValue(std::string sKey);
std::string TimestampToHRDate(double dtm);
std::string GetArrayElement(std::string s, std::string delim, int iPos);
void GetMiningParams(int nPrevHeight, bool& f7000, bool& f8000, bool& f9000, bool& fTitheBlocksActive);
std::string RetrieveTxOutInfo(const CBlockIndex* pindexLast, int iLookback, int iTxOffset, int ivOutOffset, int iDataType);
double GetBlockMagnitude(int nChainHeight);
uint256 PercentToBigIntBase(int iPercent);
std::string GetIPFromAddress(std::string sAddress);
bool SubmitProposalToNetwork(uint256 txidFee, int64_t nStartTime, std::string sHex, std::string& sError, std::string& out_sGovObj);
int GetLastDCSuperblockWithPayment(int nChainHeight);
std::string SubmitToIPFS(std::string sPath, std::string& sError);
std::string SendBusinessObject(std::string sType, std::string sPrimaryKey, std::string sValue, double dStorageFee, std::string sSignKey, bool fSign, std::string& sError);
UniValue GetDataList(std::string sType, int iMaxAgeInDays, int& iSpecificEntry, std::string sSearch, std::string& outEntry);
UserVote GetSumOfSignal(std::string sType, std::string sIPFSHash);
int GetSignalInt(std::string sLocalSignal);
double GetDifficulty(const CBlockIndex* blockindex);
bool LogLimiter(int iMax1000);
std::string PubKeyToAddress(const CScript& scriptPubKey);
void RecoverOrphanedChain(int iCondition);
void RecoverOrphanedChainNew(int iCondition);
UniValue ContributionReport();
int DeserializePrayersFromFile();
double Round(double d, int place);
void SerializePrayersToFile(int nHeight);
std::string GetFileNameFromPath(std::string sPath);

void UpdatePogPool(CBlockIndex* pindex, const CBlock& block);
void InitializePogPool(const CBlockIndex* pindexLast, int nSize, const CBlock& block);
std::string GetTitherAddress(CTransaction ctx, std::string& sNickName);
CAmount GetTitheAmount(CTransaction ctx);
double GetTitheAgeAndSpentAmount(CTransaction ctx, CBlockIndex* pindex, CAmount& spentAmount);
std::string AmountToString(const CAmount& amount);
CBlockIndex* FindBlockByHeight(int nHeight);
std::string rPad(std::string data, int minWidth);
double cdbl(std::string s, int place);
std::string AmountToString(const CAmount& amount);
std::string ExtractXML(std::string XMLdata, std::string key, std::string key_end);
bool Contains(std::string data, std::string instring);
std::string GetVersionAlert();
bool CheckNonce(bool f9000, unsigned int nNonce, int nPrevHeight, int64_t nPrevBlockTime, int64_t nBlockTime, const Consensus::Params& params);
bool RPCSendMoney(std::string& sError, const CTxDestination &address, CAmount nValue, bool fSubtractFeeFromAmount, CWalletTx& wtxNew, bool fUseInstantSend=false, std::string sOptionalData = "");


std::vector<char> ReadBytesAll(char const* filename);
std::string VectToString(std::vector<unsigned char> v);
CAmount StringToAmount(std::string sValue);
bool CompareMask(CAmount nValue, CAmount nMask);
std::string GetElement(std::string sIn, std::string sDelimiter, int iPos);
std::string TitheErrorToString(int TitheError);
std::string GetPOGBusinessObjectList(std::string sType, std::string sFields);
bool CopyFile(std::string sSrc, std::string sDest);
CAmount R20(CAmount amount);
bool PODCEnabled(int nHeight);
bool POGEnabled(int nHeight, int64_t nTime);
std::string Caption(std::string sDefault);
std::vector<std::string> Split(std::string s, std::string delim);
void MemorizeBlockChainPrayers(bool fDuringConnectBlock, bool fSubThread, bool fColdBoot, bool fDuringSanctuaryQuorum);
double GetBlockVersion(std::string sXML);
bool CheckStakeSignature(std::string sBitcoinAddress, std::string sSignature, std::string strMessage, std::string& strError);
std::string BiblepayHTTPSPost(bool bPost, int iThreadID, std::string sActionName, std::string sDistinctUser, std::string sPayload, std::string sBaseURL, std::string sPage, int iPort, 
	std::string sSolution, int iTimeoutSecs, int iMaxSize, int iBreakOnError);
std::string BiblePayHTTPSPost2(bool bPost, std::string sProtocol, std::string sDomain, std::string sPage, std::string sPayload, std::string sFileName);
std::string FormatHTML(std::string sInput, int iInsertCount, std::string sStringToInsert);
std::string GJE(std::string sKey, std::string sValue, bool bIncludeDelimiter, bool bQuoteValue);
bool InstantiateOneClickMiningEntries();
bool WriteKey(std::string sKey, std::string sValue);
std::string GetTransactionMessage(CTransactionRef tx);
bool AdvertiseChristianPublicKeypair(std::string sProjectId, std::string sNickName, bool fUnJoin, bool fForce, std::string &sError);
CWalletTx CreateAntiBotNetTx(CBlockIndex* pindexLast, double nMinCoinAge, CReserveKey& reservekey, std::string& sXML, std::string& sError);
double GetAntiBotNetWeight(CBlockIndex* pindex, CTransactionRef tx);
double GetABNWeight(const CBlock& block, bool fMining);
std::map<std::string, std::string> GetSporkMap(std::string sPrimaryKey, std::string sSecondaryKey);
std::map<std::string, CPK> GetGSCMap(std::string sGSCObjType, std::string sSearch, bool fRequireSig);
void WriteCacheDouble(std::string sKey, double dValue);
double ReadCacheDouble(std::string sKey);
bool CheckAntiBotNetSignature(CTransactionRef tx, std::string sType);
double GetVINCoinAge(CBlockIndex* pindex, CTransactionRef tx);
CAmount GetTitheAmount(CTransactionRef ctx);
CPK GetCPK(std::string sData);
std::string GetCPKData(std::string sProjectId, std::string sPK);
CAmount GetRPCBalance();


#endif
