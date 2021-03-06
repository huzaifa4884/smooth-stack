// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: transactions.proto

#include "transactions.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG
namespace models {
constexpr Transaction::Transaction(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : account_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , type_(0)

  , amount_(0){}
struct TransactionDefaultTypeInternal {
  constexpr TransactionDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~TransactionDefaultTypeInternal() {}
  union {
    Transaction _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT TransactionDefaultTypeInternal _Transaction_default_instance_;
constexpr Transactions::Transactions(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : transaction_(){}
struct TransactionsDefaultTypeInternal {
  constexpr TransactionsDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~TransactionsDefaultTypeInternal() {}
  union {
    Transactions _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT TransactionsDefaultTypeInternal _Transactions_default_instance_;
}  // namespace models
static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_transactions_2eproto[2];
static const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* file_level_enum_descriptors_transactions_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_transactions_2eproto = nullptr;

const uint32_t TableStruct_transactions_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  PROTOBUF_FIELD_OFFSET(::models::Transaction, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::models::Transaction, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::models::Transaction, account_),
  PROTOBUF_FIELD_OFFSET(::models::Transaction, type_),
  PROTOBUF_FIELD_OFFSET(::models::Transaction, amount_),
  0,
  1,
  2,
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::models::Transactions, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::models::Transactions, transaction_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 9, -1, sizeof(::models::Transaction)},
  { 12, -1, -1, sizeof(::models::Transactions)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::models::_Transaction_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::models::_Transactions_default_instance_),
};

const char descriptor_table_protodef_transactions_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\022transactions.proto\022\006models\"\213\001\n\013Transac"
  "tion\022\017\n\007account\030\001 \002(\t\0221\n\004type\030\002 \002(\0162#.mo"
  "dels.Transaction.TransactionType\022\016\n\006amou"
  "nt\030\003 \002(\005\"(\n\017TransactionType\022\t\n\005DEBIT\020\000\022\n"
  "\n\006CREDIT\020\001\"8\n\014Transactions\022(\n\013transactio"
  "n\030\001 \003(\0132\023.models.Transaction"
  ;
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_transactions_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_transactions_2eproto = {
  false, false, 228, descriptor_table_protodef_transactions_2eproto, "transactions.proto", 
  &descriptor_table_transactions_2eproto_once, nullptr, 0, 2,
  schemas, file_default_instances, TableStruct_transactions_2eproto::offsets,
  file_level_metadata_transactions_2eproto, file_level_enum_descriptors_transactions_2eproto, file_level_service_descriptors_transactions_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable* descriptor_table_transactions_2eproto_getter() {
  return &descriptor_table_transactions_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_transactions_2eproto(&descriptor_table_transactions_2eproto);
namespace models {
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* Transaction_TransactionType_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_transactions_2eproto);
  return file_level_enum_descriptors_transactions_2eproto[0];
}
bool Transaction_TransactionType_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
      return true;
    default:
      return false;
  }
}

#if (__cplusplus < 201703) && (!defined(_MSC_VER) || (_MSC_VER >= 1900 && _MSC_VER < 1912))
constexpr Transaction_TransactionType Transaction::DEBIT;
constexpr Transaction_TransactionType Transaction::CREDIT;
constexpr Transaction_TransactionType Transaction::TransactionType_MIN;
constexpr Transaction_TransactionType Transaction::TransactionType_MAX;
constexpr int Transaction::TransactionType_ARRAYSIZE;
#endif  // (__cplusplus < 201703) && (!defined(_MSC_VER) || (_MSC_VER >= 1900 && _MSC_VER < 1912))

// ===================================================================

class Transaction::_Internal {
 public:
  using HasBits = decltype(std::declval<Transaction>()._has_bits_);
  static void set_has_account(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static void set_has_type(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
  static void set_has_amount(HasBits* has_bits) {
    (*has_bits)[0] |= 4u;
  }
  static bool MissingRequiredFields(const HasBits& has_bits) {
    return ((has_bits[0] & 0x00000007) ^ 0x00000007) != 0;
  }
};

Transaction::Transaction(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:models.Transaction)
}
Transaction::Transaction(const Transaction& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  account_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    account_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (from._internal_has_account()) {
    account_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_account(), 
      GetArenaForAllocation());
  }
  ::memcpy(&type_, &from.type_,
    static_cast<size_t>(reinterpret_cast<char*>(&amount_) -
    reinterpret_cast<char*>(&type_)) + sizeof(amount_));
  // @@protoc_insertion_point(copy_constructor:models.Transaction)
}

inline void Transaction::SharedCtor() {
account_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  account_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&type_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&amount_) -
    reinterpret_cast<char*>(&type_)) + sizeof(amount_));
}

Transaction::~Transaction() {
  // @@protoc_insertion_point(destructor:models.Transaction)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void Transaction::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  account_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void Transaction::ArenaDtor(void* object) {
  Transaction* _this = reinterpret_cast< Transaction* >(object);
  (void)_this;
}
void Transaction::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void Transaction::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void Transaction::Clear() {
// @@protoc_insertion_point(message_clear_start:models.Transaction)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    account_.ClearNonDefaultToEmpty();
  }
  if (cached_has_bits & 0x00000006u) {
    ::memset(&type_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&amount_) -
        reinterpret_cast<char*>(&type_)) + sizeof(amount_));
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Transaction::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // required string account = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          auto str = _internal_mutable_account();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          #ifndef NDEBUG
          ::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "models.Transaction.account");
          #endif  // !NDEBUG
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // required .models.Transaction.TransactionType type = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 16)) {
          uint64_t val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          if (PROTOBUF_PREDICT_TRUE(::models::Transaction_TransactionType_IsValid(val))) {
            _internal_set_type(static_cast<::models::Transaction_TransactionType>(val));
          } else {
            ::PROTOBUF_NAMESPACE_ID::internal::WriteVarint(2, val, mutable_unknown_fields());
          }
        } else
          goto handle_unusual;
        continue;
      // required int32 amount = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 24)) {
          _Internal::set_has_amount(&has_bits);
          amount_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  _has_bits_.Or(has_bits);
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* Transaction::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:models.Transaction)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required string account = 1;
  if (cached_has_bits & 0x00000001u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::VerifyUTF8StringNamedField(
      this->_internal_account().data(), static_cast<int>(this->_internal_account().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SERIALIZE,
      "models.Transaction.account");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_account(), target);
  }

  // required .models.Transaction.TransactionType type = 2;
  if (cached_has_bits & 0x00000002u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteEnumToArray(
      2, this->_internal_type(), target);
  }

  // required int32 amount = 3;
  if (cached_has_bits & 0x00000004u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(3, this->_internal_amount(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:models.Transaction)
  return target;
}

size_t Transaction::RequiredFieldsByteSizeFallback() const {
// @@protoc_insertion_point(required_fields_byte_size_fallback_start:models.Transaction)
  size_t total_size = 0;

  if (_internal_has_account()) {
    // required string account = 1;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_account());
  }

  if (_internal_has_type()) {
    // required .models.Transaction.TransactionType type = 2;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::EnumSize(this->_internal_type());
  }

  if (_internal_has_amount()) {
    // required int32 amount = 3;
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32SizePlusOne(this->_internal_amount());
  }

  return total_size;
}
size_t Transaction::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:models.Transaction)
  size_t total_size = 0;

  if (((_has_bits_[0] & 0x00000007) ^ 0x00000007) == 0) {  // All required fields are present.
    // required string account = 1;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_account());

    // required .models.Transaction.TransactionType type = 2;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::EnumSize(this->_internal_type());

    // required int32 amount = 3;
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32SizePlusOne(this->_internal_amount());

  } else {
    total_size += RequiredFieldsByteSizeFallback();
  }
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Transaction::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    Transaction::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Transaction::GetClassData() const { return &_class_data_; }

void Transaction::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<Transaction *>(to)->MergeFrom(
      static_cast<const Transaction &>(from));
}


void Transaction::MergeFrom(const Transaction& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:models.Transaction)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x00000007u) {
    if (cached_has_bits & 0x00000001u) {
      _internal_set_account(from._internal_account());
    }
    if (cached_has_bits & 0x00000002u) {
      type_ = from.type_;
    }
    if (cached_has_bits & 0x00000004u) {
      amount_ = from.amount_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Transaction::CopyFrom(const Transaction& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:models.Transaction)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Transaction::IsInitialized() const {
  if (_Internal::MissingRequiredFields(_has_bits_)) return false;
  return true;
}

void Transaction::InternalSwap(Transaction* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &account_, lhs_arena,
      &other->account_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(Transaction, amount_)
      + sizeof(Transaction::amount_)
      - PROTOBUF_FIELD_OFFSET(Transaction, type_)>(
          reinterpret_cast<char*>(&type_),
          reinterpret_cast<char*>(&other->type_));
}

::PROTOBUF_NAMESPACE_ID::Metadata Transaction::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_transactions_2eproto_getter, &descriptor_table_transactions_2eproto_once,
      file_level_metadata_transactions_2eproto[0]);
}

// ===================================================================

class Transactions::_Internal {
 public:
};

Transactions::Transactions(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned),
  transaction_(arena) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:models.Transactions)
}
Transactions::Transactions(const Transactions& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      transaction_(from.transaction_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:models.Transactions)
}

inline void Transactions::SharedCtor() {
}

Transactions::~Transactions() {
  // @@protoc_insertion_point(destructor:models.Transactions)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void Transactions::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
}

void Transactions::ArenaDtor(void* object) {
  Transactions* _this = reinterpret_cast< Transactions* >(object);
  (void)_this;
}
void Transactions::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void Transactions::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void Transactions::Clear() {
// @@protoc_insertion_point(message_clear_start:models.Transactions)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  transaction_.Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Transactions::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // repeated .models.Transaction transaction = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_transaction(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<10>(ptr));
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* Transactions::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:models.Transactions)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .models.Transaction transaction = 1;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_transaction_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(1, this->_internal_transaction(i), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:models.Transactions)
  return target;
}

size_t Transactions::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:models.Transactions)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .models.Transaction transaction = 1;
  total_size += 1UL * this->_internal_transaction_size();
  for (const auto& msg : this->transaction_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Transactions::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    Transactions::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Transactions::GetClassData() const { return &_class_data_; }

void Transactions::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<Transactions *>(to)->MergeFrom(
      static_cast<const Transactions &>(from));
}


void Transactions::MergeFrom(const Transactions& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:models.Transactions)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  transaction_.MergeFrom(from.transaction_);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Transactions::CopyFrom(const Transactions& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:models.Transactions)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Transactions::IsInitialized() const {
  if (!::PROTOBUF_NAMESPACE_ID::internal::AllAreInitialized(transaction_))
    return false;
  return true;
}

void Transactions::InternalSwap(Transactions* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  transaction_.InternalSwap(&other->transaction_);
}

::PROTOBUF_NAMESPACE_ID::Metadata Transactions::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_transactions_2eproto_getter, &descriptor_table_transactions_2eproto_once,
      file_level_metadata_transactions_2eproto[1]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace models
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::models::Transaction* Arena::CreateMaybeMessage< ::models::Transaction >(Arena* arena) {
  return Arena::CreateMessageInternal< ::models::Transaction >(arena);
}
template<> PROTOBUF_NOINLINE ::models::Transactions* Arena::CreateMaybeMessage< ::models::Transactions >(Arena* arena) {
  return Arena::CreateMessageInternal< ::models::Transactions >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
