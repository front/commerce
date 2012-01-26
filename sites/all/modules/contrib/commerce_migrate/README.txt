Provides:
- An Entity API migrate destination plugin.
- Migrate destination field handlers for commerce fields (reference fields, price field)
- Migrate destination plugin for commerce product types.
- A submodule (commerce_migrate_ubercart) providing the beginnings of an upgrade path from Ubercart (D7) to Commerce

Todo:
- Provide a commerce_migrate_example module, with sample migrations importing commerce data from CSV files.

Ubercart migration
------------------
What currently works:
- Product types are created from ubercart product classes.
- Each product type gets its own migration.
- Images are migrated from the uc_product_image field of ubercart products to the field_image field of commerce products.
- Each product type gets its own (optional) node migration, which creates the matching product_display nodes.
- Customer billing profiles are created from the billing info of each ubercart order.
- Orders (and line items)

What doesn't work:
- Taxes
- Handling the case when the target product type / sku that we're creating already exists.
- Things I'm not even aware of :P

Migrate
-------
Migrate (http://drupal.org/project/migrate) is one of the two solutions for importing external data into Drupal,
the other being Feeds (see http://drupal.org/project/feeds and http://drupal.org/project/commerce_feeds)

Resources:
- http://cyrve.com/import
- http://www.gizra.com/content/data-migration-part-1
- http://www.gizra.com/content/data-migration-part-2
