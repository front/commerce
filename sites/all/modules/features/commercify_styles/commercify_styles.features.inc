<?php
/**
 * @file
 * commercify_styles.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function commercify_styles_image_default_styles() {
  $styles = array();

  // Exported image style: product_display_large
  $styles['product_display_large'] = array(
    'name' => 'product_display_large',
    'effects' => array(
      4 => array(
        'label' => 'Skaler',
        'help' => 'Skalering vil beholde størrelsesforhold i det originale bildet. Hvis bare en dimensjon er oppgitt, så beregnes den andre dimensjonen.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '410',
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: product_display_thumb
  $styles['product_display_thumb'] = array(
    'name' => 'product_display_thumb',
    'effects' => array(
      7 => array(
        'label' => 'Skaler og beskjær',
        'help' => 'Skaler og beskjær vil beholde størrelsesforhold i det originale bildet og så beskjære den største dimensjonen. Dette er mest nyttig for å lage perfekte kvadratiske miniatyrbilder uten å strekke bildet.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '102',
          'height' => '102',
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: thumbnail_front
  $styles['thumbnail_front'] = array(
    'name' => 'thumbnail_front',
    'effects' => array(
      3 => array(
        'label' => 'Skaler',
        'help' => 'Skalering vil beholde størrelsesforhold i det originale bildet. Hvis bare en dimensjon er oppgitt, så beregnes den andre dimensjonen.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '142',
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => '1',
      ),
      5 => array(
        'label' => 'Define canvas',
        'help' => 'Define the size of the working canvas and background color, this controls the dimensions of the output image.',
        'effect callback' => 'canvasactions_definecanvas_image',
        'form callback' => 'canvasactions_definecanvas_form',
        'summary theme' => 'canvasactions_definecanvas_summary',
        'module' => 'imagecache_canvasactions',
        'name' => 'canvasactions_definecanvas',
        'data' => array(
          'RGB' => array(
            'HEX' => 'ddd',
          ),
          'under' => 1,
          'exact' => array(
            'width' => '142',
            'height' => '220',
            'xpos' => 'center',
            'ypos' => 'center',
          ),
          'relative' => array(
            'leftdiff' => '',
            'rightdiff' => '',
            'topdiff' => '',
            'bottomdiff' => '',
          ),
        ),
        'weight' => '2',
      ),
      6 => array(
        'label' => 'Overlay (watermark)',
        'help' => 'Choose the file image you wish to use as an overlay, and position it in a layer on top of the canvas.',
        'effect callback' => 'canvasactions_file2canvas_image',
        'form callback' => 'canvasactions_file2canvas_form',
        'summary theme' => 'canvasactions_file2canvas_summary',
        'module' => 'imagecache_canvasactions',
        'name' => 'canvasactions_file2canvas',
        'data' => array(
          'xpos' => 'left',
          'ypos' => 'top',
          'alpha' => '100',
          'path' => 'sites/all/themes/allertheme/images/img_thumboverlay.png',
        ),
        'weight' => '3',
      ),
    ),
  );

  return $styles;
}
