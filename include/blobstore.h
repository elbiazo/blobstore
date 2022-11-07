#pragma once
#include "rust/cxx.h"
#include <memory>

namespace org {
namespace blobstore {

struct MultiBuf;
struct BlobMetadata;

class BlobstoreClient {
public:
  BlobstoreClient();
  uint64_t put(MultiBuf &buf) const;
  void tag(uint64_t blobid, rust::Str tag) const;
  BlobMetadata metadata(uint64_t blobid) const;

private:
  class impl;
  std::shared_ptr<impl> impl;
};

std::unique_ptr<BlobstoreClient> new_blobstore_client();
void pass_vec(rust::Vec<uint8_t> &data, uint8_t value);
void test();
} // namespace blobstore
} // namespace org
